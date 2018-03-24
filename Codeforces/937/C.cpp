#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

double k, d, t, ti, p, ans, fac, rest;
const double eps = 1e-10;

int main(){
	scanf("%lf%lf%lf", &k, &d, &t);
	ti = ll((k - 1) / d) + 1;
	p = ti * d;
	ans = 0;
	fac = ll(2 * t / (p + k));
	ans += fac * p;
	rest = 2 * t - (p + k) * fac;
	if (rest < 2 * k) ans += rest / 2;
	else ans += k + rest - 2 * k;
	printf("%.10f", ans);
	return 0;
}