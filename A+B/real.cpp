#include <bits/stdc++.h>

long long rec2[20];
long long rec[20];
long long inp[20];
long long l, u, v, w;
int n, m, op;

inline int lowbit(int x) {
    return x&-x;
}

void add(int i, int x, long long *arr) {
    for (; i <= n; i += lowbit(i)) arr[i] += x;
}

long long query(int i, long long *arr) {
    long long ret = 0;
    for (; i; i -= lowbit(i)) ret += arr[i];
    return ret;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", inp + i);
        add(i, inp[i] - l, rec);
        add(i, (i - 1) * (inp[i] - l), rec2);
        l = inp[i];
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d%lld%lld", &op, &u, &v);
        if (op == 1) {
            scanf("%lld", &w);
            add(u, w, rec);
            add(v + 1, -w, rec);
            add(u, w * (u - 1), rec2);
            add(v + 1, -w * v, rec2);
        } else {
            printf("%lld\n", query(v, rec) * v - query(v, rec2) - query(u - 1, rec) * (u - 1) + query(u - 1, rec2));
        }
    }
    return 0;
}