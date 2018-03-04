#include <bits/stdc++.h>
using namespace std;

deque<int> maxq, minq;
int rec[1000006];
int n, k;

void min_p() {
	for (int i = 1; i <= n; i++) {
		while (!minq.empty() && minq.back() >= rec[i]) {
			minq.pop_back();
		}
		minq.push_back(rec[i]);
		if (i > k) if (minq.front() == rec[i - k]) minq.pop_front();
		if (i >= k) printf("%d ", minq.front());
	} puts("");
}

void max_p() {
	for (int i = 1; i <= n; i++) {
		while (!maxq.empty() && maxq.back() <= rec[i]) {
			maxq.pop_back();
		}
		maxq.push_back(rec[i]);
		if (i > k) if (maxq.front() == rec[i - k]) maxq.pop_front();
		if (i >= k) printf("%d ", maxq.front());
	} puts("");
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", rec + i);
	}
	min_p();
	max_p();
	return 0;
}