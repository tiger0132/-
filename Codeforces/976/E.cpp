#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int SA_SIGN = 300000;

priority_queue<pair<ll, int> > pq;
ll hp[200005], dmg[200005];
ll spell_a[200005];
ll spell_b[200005];
bool spell_a_used;
bool vis[500005];
ll a, b, ans;
int n;

int main() {
	scanf("%d%I64d%I64d", &n, &a, &b);
	for (int i = 1; i <= n; i++) {
		scanf("%I64d%I64d", hp+i, dmg+i);
		if (a && b) {
			spell_a[i] = (hp[i] << a) - max(hp[i], dmg[i]);
			pq.push(make_pair(spell_a[i], i + SA_SIGN));
		}
		if (b) {
			spell_b[i] = max(hp[i], dmg[i]) - dmg[i];
			pq.push(make_pair(spell_b[i], i));
		}
		ans += dmg[i];
	}
	while (b && !pq.empty()) {
		pair<ll, int> pos = pq.top(); pq.pop();
		if (pos.first <= 0) break;
		if (/*vis[pos.second] || */(spell_a_used && pos.second / SA_SIGN)) continue;
		spell_a_used |= pos.second / SA_SIGN; b -= !(vis[pos.second % SA_SIGN]);
		vis[pos.second % SA_SIGN] = 1; b--;
		ans += pos.first;
	}
	printf("%I64d", ans);
	return 0;
}