#include <bits/stdc++.h>
using namespace std;

int z[1000005], ans = 0x3f3f3f3f, maxz = -0x3f3f3f3f, n;
char s[1000005];

void Z() {
	int l = 0, r = 0; // z-box: [l, r]
	for (int i = 1; i < n; i++) { // z[0]没有意义，于是就从1开始
		if (i > r) { // 如果i不在z-box中
			l = r = i; // 然后把z-box移到i的位置
			while (r < n && s[r - l] == s[r]) r++; // 如果匹配，就让z-box变大
			z[i] = r - l; // 算出对应的z[i](因为l就在i的位置，所以r - l)
		} else { // 否则i在z-box中
			int cur = i - l; // 代表z-box中的i在前缀中对应的位置
			if (i + z[cur] - 1 < r) { // 如果前缀中的z值没有越过z-box
				z[i] = z[cur]; // 直接复制
			} else { // 如果越过了z-box
				l = i; // 更新z-box的位置
				while (r < n && s[r] == s[r - l]) r++; // 拓展z-box
				z[i] = r - l;
			}
		}
		r--;
	}
}


int main() {
	gets(s);
	n = strlen(s);
	if (n < 3) {
		puts("Just a legend");
		return 0;
	}
	if (s == string(n, s[0])) {
		puts(s + 2);
		return 0;
	}
	Z();
	for (int i = 1; i < n; i++) {
		if (z[i] == n - i && maxz >= n - i && z[i] < n - 1) {
			ans = n - i;
			break;
		}
		maxz = max(maxz, z[i]);
	}
	if (ans == 0x3f3f3f3f) {
		puts("Just a legend");
	} else {
		s[ans] = 0;
		puts(s);
	}
} 