#include <bits/stdc++.h>
using namespace std;

char pattern[1000006], src[2000006];
int z[2000006], nxt[2000006];
int n, m;

void Z() {
	int l = 0, r = 0; 
	for (int i = 1; i < n; i++) { 
		if (i > r) { 
			l = r = i; 
			while (r < n && src[r - l] == src[r]) r++; 
			z[i] = r - l; 
		} else { 
			int cur = i - l; 
			if (i + z[cur] - 1 < r) { 
				z[i] = z[cur]; 
			} else { 
				l = i; 
				while (r < n && src[r] == src[r - l]) r++; 
				z[i] = r - l;
			}
		}
		r--;
	}
}

int main() {
	scanf("%s%s", src, pattern);
	m = strlen(pattern);
	pattern[strlen(pattern)] = '$';
	strcat(pattern, src);
	strcpy(src, pattern);
	n = strlen(src);
	Z();
	puts(src);
	for (int i = 0; i < n; i++) {
		printf("%d ", z[i]);
	}
	puts("");
	for (int i = 1; i < n; i++) {
		if (z[i] == m) {
			printf("%d\n", i - m);
		}
	}
	for (int i = 0; i < m; i++) {
		if (i + z[i] >= m) continue;
		nxt[i + z[i]] = max(nxt[i + z[i]], z[i]);
	}
	for (int i = 0; i < m; i++) {
		printf("%d ", nxt[i]);
	} puts("");
	for (int i = m - 1; i >= 0; i--) {
		nxt[i] = max(nxt[i + 1] - 1, nxt[i]);
	}
	for (int i = 0; i < m; i++) {
		printf("%d ", nxt[i]);
	}
	return 0;
}