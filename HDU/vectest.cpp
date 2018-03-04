#include <bits/stdc++.h>
using namespace std;

vector<int> vec;
int c;

int main() {
	for (int i = 1; i <= 1000000; i++) {
		vec.push_back(1);
		if (vec.capacity() != c) {
			printf("change to: %d\n", c = vec.capacity());
		}
	}
	// vec.clear();
	printf("change to: %d\n", c = vec.capacity());
	// vec.swap(*new vector<int>());
	vec.reserve(0);
	printf("change to: %d\n", c = vec.capacity());
	while (1);
}