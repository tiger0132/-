//BUG AGAIN
//NEED DEBUG

#include <bits/stdc++.h>
using namespace std;

int result[16][16], cnt;
bool used[100000007];
int __details[16][2]; 
int n, arr[16];

void bit(int x) {
	if (x > 1) {
		bit(x >> 1);
	}
	cout << (x & 1);
}

//High unreadability!
void dfs(int dep, int details) {
	if (dep > n) {
		unsigned __hash = 0;
		for (int i = 1; i <= n; i++) {
			__hash = (__hash * __details[i - 1][0]) % 100000007;
//			bit(__details[i - 1][0]); cout << " "; bit(__details[i][1]); cout << endl;
			if (__details[i - 1][0] != __details[i][1]) {
				return;
			}
		}
		if (details == (1 << (n << 1)) - 1 && !used[__hash]) {
		for (int i = 1; i <= n; i++) {
//			__hash = (__hash * __details[i - 1][0]) % 100000007;
			bit(__details[i - 1][0]); cout << " "; bit(__details[i][1]); cout << endl;
//			if (__details[i - 1][0] != __details[i][1]) {
//				return;
//			}
		}
			used[__hash] = true;
			cnt++;
		} 
	} else {
		for (int i = 0; i < (1 << n); i++) { 
			if (!((i >> (dep - 1)) & 1)) {
				for (int j = 0; j < (1 << n); j++) {
					int score = 0, mask = 0;
					if (!~(i | ~j)) {
						for (int k = 1, r = 0; k < (1 << n); k <<= 1, r++) {
							if (i & k) {
								int tmp = ((details >> (r << 1)) & 3);
								score += ((j & k) ? 3 : 1); //ERROR
								if (tmp == 0 && !(j & k)) {
									__details[r][0] |= (1 << ((dep - 1) << 1));
									__details[dep][1] |= (1 << (r << 1));
									mask |= (1 << (r << 1));
								} else if (tmp == 1 || (j & k)) {
									__details[r][0] |= (3 << ((dep - 1) << 1));
									__details[dep][1] |= (3 << (r << 1));
									mask |= (3 << (r << 1));
								}
							}
						}
						//Error on score calculation 
						if (score == arr[dep]) {
							dfs(dep + 1, (details | mask));
						}
					}
				}
			}
		}
	}
}

int main() {
	#ifdef ONLINE_JUDGE
	freopen("history.in", "r", stdin);
	freopen("history.out", "w", stdout);
	#endif 
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dfs(1, 0);
	cout << cnt;
} 
