#include <bits/stdc++.h>
using namespace std;

typedef unsigned char uchar;

const int list_cnt = 12, length = 4;

const char values[list_cnt][length + 1] = {
	"��ǿ",
	"����",
	"����",
	"��г",
	"����",
	"ƽ��",
	"����",
	"����",
	"����",
	"��ҵ",
	"����",
	"����"
};

const int l1 = list_cnt, l2 = l1 * l1;

char str[1000];
uchar tmp;
int n;

int main() {
	gets(str);
	n = strlen(str);
	for (int i = 0; i < n; i++) {
		tmp = str[i];
		// low - mid - high
		printf("%s%s%s", values[tmp % l1], values[tmp / l1 % l1], values[tmp / l2]);
	}
	return 0;
}

// ���ٵ����� 
