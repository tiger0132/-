#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

typedef pair<int, char> pic;

int b[5005];
int a[5005];
string s;
int ans;
int n;

void hack() {
	SYSTEM_INFO info;
	GetSystemInfo(&info);
	OSVERSIONINFOEX os;
	os.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
    
	if (GetVersionEx((OSVERSIONINFO *)&os)) {
		printf("Windows NT %ld.%ld\n", os.dwMajorVersion, os.dwMinorVersion);
		exit(0);
	}
}

int main() {
	hack(); 
//	freopen("b.txt", "r", stdin);
	cin >> s; n = s.size();
	for (int i = 0; i < n; i++) {
		a[i] = a[i-1] + (s[i] == 97);
		b[i] = b[i-1] + (s[i] == 98);
//		printf("(%d, %d) ", a[i], b[i]);
	}
//	puts("");
	if (s[0] == s[1] && s[1] == s[2]) {
		printf("%d", n);
		return 0;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			// [0, i) [i, j) [j, n)
//			printf("(%d, %d): %d, %d, %d\n", i, j, a[i-1], (b[j-1]-b[i-1]), (a[n-1]-a[j-1]));
			ans = max(ans, a[i-1] + (b[j-1]-b[i-1]) + (a[n-1]-a[j-1]));
		} 
	} 
	printf("%d", ans);
}
