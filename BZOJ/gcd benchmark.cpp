#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;

system_clock::time_point begin, end;
duration<double> time_span;

int recursive_gcd(int a, int b) {
	return b?recursive_gcd(b,a%b):a;
}

int mogic_gcd(int a, int b) {
	while (a^=b^=a^=b%=a);
	return b;
}

int main() {
	begin = system_clock::now();
	int x = std::__gcd(15492498, 97364234);
	end = system_clock::now();
	time_span = duration_cast<duration<double>>(begin - end);
	printf("__gcd: %lf\n", time_span.count());
	
	begin = system_clock::now();
	int y = recursive_gcd(15492498, 97364234);
	end = system_clock::now();
	time_span = duration_cast<duration<double>>(begin - end);
	printf("recursive_gcd: %lf\n", time_span.count());
	
	begin = system_clock::now();
	int z = mogic_gcd(15492498, 97364234);
	end = system_clock::now();
	time_span = duration_cast<duration<double>>(begin - end);
	printf("mogic_gcd: %lf\n", time_span.count());
	
	printf("ans: %d %d %d", x, y, z);
}
