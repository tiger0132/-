#include <bits/stdc++.h>
using namespace std;

struct s {
	int x;
	bool operator<(const s& rhs) {
		return x < rhs.x;
	}
} xxx[10];

int main() {
	// do something...
	sort(xxx, xxx + 10);
}