#include <bits/stdc++.h>
using namespace std;

struct node {
	int a, b;
	node(int x, int y) : a(x), b(y) {}
	node() {}
} rec[31];

char cmd[100005];
int n, m, ans;
char name[2];

int main() {
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%s", name);
		scanf("%d%d", &rec[*name - 'A'].a, &rec[*name - 'A'].b);
	}
	while (~scanf("%s", cmd + 1)) {
		stack<node> st;
		n = strlen(cmd + 1);
		ans = 0;
		for (int i = 1; i <= n; i++) {
			if (isalpha(cmd[i])) {
				st.push(rec[cmd[i] - 'A']);
//				printf("push: %d %d\n", rec[cmd[i] - 'A']);
			}
			if (cmd[i] == ')') {
				node y = st.top(); st.pop();
				node x = st.top(); st.pop();
//				printf("mul: %d %d %d %d\n", x, y);
				if (x.b != y.a) {
					puts("error");
					goto end;
				}
				ans += x.a * x.b * y.b;
				st.push(node(x.a, y.b));
			}
		}
		printf("%d\n", ans);
		end:;
	}
}
/*
9
A 50 10
B 10 20
C 20 5
D 30 35
E 35 15
F 15 5
G 5 10
H 10 20
I 20 25
A
B
C
(AA)
(AB)
(AC)
(A(BC))
((AB)C)
(((((DE)F)G)H)I)
(D(E(F(G(HI)))))
((D(EF))((GH)I))
*/