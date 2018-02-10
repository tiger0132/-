#include <bits/stdc++.h>
#define cnv(x, y) ((x) * m + (y))
using namespace std;

struct edg {
	int x, y, z;
}; 

int x[1023][1023];
int y[1023][1023];
int z[1023][1023];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m-1; j++) {
			scanf("%d", x[i]+j);
		}
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", y[i]+j);
		}
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < m-1; j++) {
			scanf("%d", z[i]+j);
		}
	}
	for (int i = 0; i < n; i++) {
		
	}
	spfa();
} 
