// WHY DP? THAT SOLUTION SOUNDS BETTER... ————LYH

#include <cstdio>
#include <queue>
using namespace std;

priority_queue<int> pq;
long long ans;
int n, t;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		pq.push(t);
		if (i && pq.top() > t) {
			ans += pq.top() - t;
			pq.pop();
			pq.push(t);
		}
	}
	printf("%lld", ans);
	return 0;
}