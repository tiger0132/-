#include <bits/stdc++.h>
using namespace std;

int rec[1000005], n, a, c, __;
vector<int> equ[20000005];
char ch, _ = 48;
string s;

void bit(int x) {
	if (x>1) bit(x>>1);
	s += ((x&1)?'\t':' ');
}

int main() {
    scanf("%d", &__); getchar();
    while ((ch = getchar()) != '\n') {
    	if (ch != _ && __ == 8) {
    		printf("%d;", c);
    		c = 0;
    	}
    	c++; _ = ch;
        rec[n] = rec[n - 1];
        if (ch == 48) rec[n]--;
        else rec[n]++;
        n++;
    }
    printf("%d");
	puts(s.c_str());
    equ[n].push_back(-1);
    for (int i = 0; i < n; i++) {
        equ[rec[i] + n].push_back(i);
    }
    for (int i = 0; i <= 2 * n; i++) {
        if (equ[i].size() < 2) continue;
        a = max(a, equ[i].back() - equ[i].front());
    }
    printf("%d", a);
}
