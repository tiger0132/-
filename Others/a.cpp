#include <cstdio>

struct st {
    int x, y;
};

int main() {
    st v;
    v.x = 1;
    v.y = 2;
    printf("%d %d", v);
    while (1);
}