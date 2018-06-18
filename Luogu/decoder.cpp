#include <bits/stdc++.h>
using namespace std;

typedef unsigned char uchar;

const int list_cnt = 12, length = 4;

const char values[list_cnt][length + 1] = {
	"富强",
	"民主",
	"文明",
	"和谐",
	"自由",
	"平等",
	"公正",
	"法治",
	"爱国",
	"敬业",
	"诚信",
	"友善"
};

const int digits = 3;

char str[1000];
uchar tmp, t;
int n;

int main() {
	gets(str);
	n = strlen(str);
	for (int i = 0; i < n; ) {
		tmp = 0;
		t = 1;
		for (int _ = 0; _ < digits; _++, t *= list_cnt, i += length) {
			for (int j = 0; j < list_cnt; j++) {
				for (int k = 0; k < length; k++) {
					if (str[i+k] != values[j][k]) goto fail;
				}
				tmp += j * t;
				break;
				fail:;
			}
		}
		putchar((char)tmp);
	}
	return 0;
}


