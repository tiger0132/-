#include <bits/stdc++.h>
#define ORIG 8192
using namespace std;
 
struct r {
	int x, y, s;
	bool dx; 
	inline bool operator<(const r& val) const {
		return val.x < x;
	}
};
 
struct o {
	bool type; // 0: F, 1: T
	int val;
};

int dp[2][16383];
char str[8191];
int x, y, n, m;
vector<o> op;
bool axis;

void proc() {
	char r_;
	int c;
	m = strlen(str);
	r_ = *str; c = 1;
	for (int i = 1; i < m; i++) {
		if (str[i] != r_) {
			if (r_ == 'T') while (c--) op.push_back({1, 0});
			else op.push_back({0, c});
			r_ = str[i];
			c = 1;
		} else {
			c++;
		}
	}
	if (r_ == 'T') while (c--) op.push_back({1, 0});
	else op.push_back({0, c});
	n = op.size();
}

int main() {
	scanf("%s%d%d", str, &x, &y);
	proc();
	dp[0][ORIG] = dp[1][ORIG] = 1;
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", op[i].type, op[i].val);
		if (op[i].type) {
			axis ^= 1;
		} else {
			if (i == 0) {
				printf("dp[%d][%d] = 1;\n", axis, ORIG+op[i].val);
				dp[axis][ORIG+op[i].val] = 1;
			} else {
				for (int j = ORIG-m; j <= ORIG+m; j++) {
					printf("dp[%d][%d] = dp[%d][%d] = dp[%d][%d];\n", axis, j+op[i].val, axis, j-op[i].val, axis, j);
					dp[axis][j+op[i].val] = dp[axis][j-op[i].val] = dp[axis][j];
				}
			}
		}
	}
	for (int i = ORIG+n; i >= ORIG; i--) {
		
	}
	puts((dp[0][ORIG+x] && dp[1][ORIG+y]) ? "Yes" : "No");
}
