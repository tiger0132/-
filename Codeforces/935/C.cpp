#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

ld dis, dx, dy, nx, ny; 
ld r, x1_, y1_, x2_, y2_;

// 19

int main() {
	cin >> r >> x1_ >> y1_ >> x2_ >> y2_;
	
	dx = x1_ - x2_;
	dy = y1_ - y2_;

	dis = sqrtl(dx * dx + dy * dy);
	// if (x2_ > x1_) dx *= -1;
	// if (y2_ > y1_) dy *= -1;
	nx = x2_ + (dx / dis * (dis + r)) / 2;
	ny = y2_ + (dy / dis * (dis + r)) / 2;
	cout << setprecision(16) << nx << " " << ny << " " << setprecision(15) << (dis + r) / 2;
	#ifdef LOCAL
	getchar();
	getchar();
	#endif
}

#if 0
3.7677669529663684 3.7677669529663684 3.914213562373095
3.7677669529663688 3.7677669529663688 3.9142135623730950
#endif