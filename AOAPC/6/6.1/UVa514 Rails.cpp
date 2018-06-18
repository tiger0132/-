#include <bits/stdc++.h>
using namespace std;

int a, b, rec[1003];
bool flag;
int n;

int main() {
	while (~scanf("%d", &n) && n) {
		again:
		stack<int> s;
		memset(rec, 0, sizeof(rec));
		for (int i = 1; i <= n; i++) {
			scanf("%d", rec + i);
			if (!rec[i]) {
				puts("");
				goto end;
			}
		}
		flag = a = b = 1;
		while (b <= n) {
			if (a == rec[b]) {
				a++;
				b++;
			} else if (!s.empty() && (s.top() == rec[b])) {
				s.pop();
				b++;
			} else if (a <= n) {
				s.push(a++);
			} else {
				flag = 0;
				break;
			}
		}
		puts(flag ? "Yes" : "No");
		goto again;
		end:;
	}
}