#include <bits/stdc++.h>
using namespace std;

int n, m, a;

int main() {
	scanf("%d%d%d", &n, &m, &a);
	printf("%d", ((n+a-1)/a)*((m+a-1)/a));
}
