#include <bits/stdc++.h>
using namespace std;

string maze_name;
int r0, c0, r1, c1, dir, r2, c2;

const char dirs[] = "NESW";
const char turns[] = "FLR";
const int N = 20;

int find_dir(char c) {
	return strchr(dirs, c) - dirs;
}

int find_tern(char c) {
	return strchr(turns, c) - turns;
}

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

int has_edge[N][N][N][N];

void read_edge() {
	memset(has_edge, 0, sizeof(has_edge));
	int pr, pc, pdir, pturn;
	string temp;
	while (~scanf("%d", &pr)) {
		if (!pr) break;
		scanf("%d", &pc);
		while (cin >> temp) {
			if (temp == "*") break;
			pdir = find_dir(temp[0]);
			for (int i = 1; i < temp.size(); i++) {
				pturn = find_tern(temp[i]);
				has_edge[pr][pc][pdir][pturn] = 1;
			}
		}
	}
}

bool read_list() {
	cin >> maze_name;
	if (maze_name == "END") return 0;
	puts(maze_name.c_str());
	char dir0[2];
	scanf("%d%d%1s%d%d", &r0, &c0, dir0, &r2, &c2);
	dir = find_dir(*dir0);
	r1 = r0 + dr[dir];
	c1 = c0 + dc[dir];
	read_edge();
	return 1;
}

struct Node {
	int r, c, dir;
	Node(int r_ = 0, int c_ = 0, int dir_ = 0) : r(r_), c(c_), dir(dir_) {}
};

int d[N][N][N];
Node p[N][N][N];

Node walk(const Node& u, int turn) {
	int dir_ = u.dir;
	if (turn == 1) dir_ = (dir_ + 3) % 4;
	if (turn == 2) dir_ = (dir_ + 1) % 4;
	return Node(u.r + dr[dir_], u.c + dc[dir_], dir_);
}

bool chk(int r, int c) {
	return r >= 1 && r <= 9 && c >= 1 && c <= 9;
}

void print_ans(Node u) {
	vector<Node> nodes;
	while (1) {
		nodes.push_back(u);
		if (!d[u.r][u.c][u.dir]) break;
		u = p[u.r][u.c][u.dir];
	}
	nodes.push_back(Node(r0, c0, dir));
	int cnt = 0;
	for (int i = nodes.size() - 1; i >= 0; i--) {
		if (cnt % 10 == 0) putchar(' ');
		printf(" (%d,%d)", nodes[i].r, nodes[i].c);
		if (++cnt % 10 == 0) puts("");
	}
	if (nodes.size() % 10) puts("");
}

void solve() {
	queue<Node> q;
	memset(d, -1, sizeof(d));
	Node n1(r1, c1, dir);
	q.push(n1);
	d[r1][c1][dir] = 0;
	while (!q.empty()) {
		Node u = q.front(); q.pop();
		if (u.r == r2 && u.c == c2) {
			print_ans(u);
			return;
		}
		for (int i = 0; i < 3; i++) {
			Node v = walk(u, i);
			if (has_edge[u.r][u.c][u.dir][i] && chk(v.r, v.c) && d[v.r][v.c][v.dir] < 0) {
				d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;
				p[v.r][v.c][v.dir] = u;
				q.push(v);
			}
		}
	}
	puts("  No Solution Possible");
}

int main() {
	while (read_list()) {
		solve();
	}
	return 0;
}

#if 0
SAMPLE
3 1 N 3 3
1 1 WL NR *
1 2 WLF NR ER *
1 3 NL ER *
2 1 SL WR NF *
2 2 SL WF ELF *
2 3 SFR EL *
0
NOSOLUTION
3 1 N 3 2
1 1 WL NR *
1 2 NL ER *
2 1 SL WR NFR *
2 2 SR EL *
0
END
#endif