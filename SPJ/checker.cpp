#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int hash1, hash2, score;
string ipt;

int main(int argc, char **argv) {
    // registerTestlibCmd(argc, argv);
	// ipt = ouf.readString();
	cin >> ipt;
	for (int i = 0; i < ipt.size(); i++) {
		hash1 = (hash1 + ipt[i] * 233 + 17) % 311111;
		hash2 = (hash2 + ipt[i] * 191 + 23) % 1311311;
	}
	score = (23333ll * hash1 + 13131ll * hash2) % 101ll;	
	// score = (23333ll * hash1 + 13131 * hash2) % 101ll;
	// quitp(score / 100., "%d points owo.", score);
	printf("%d points owo.", score);
	return 0;
}

// geography 6

// village 97
// fuc 98
// 01nuzx 99
// ***************** 100