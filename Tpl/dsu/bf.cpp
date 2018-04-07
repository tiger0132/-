#include <bits/stdc++.h>
using namespace std;



int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%s%d", op, &u);
		switch (*op) {
			case 'f': printf("%d\n", find(u)); break;
			case 'm': scanf("%d", &v); puts(merge(u, v) ? "YE5" : "N0"); break;
			case 'q': printf("%d\n", query(u));
		}
	}
	return 0;
}