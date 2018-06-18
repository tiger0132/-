#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int main() {
	for (int i = 0; i <= 8192; i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
		printf("%4d", i);
	}
	return 0;
}