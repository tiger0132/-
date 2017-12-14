#include <bits/stdc++.h>
using namespace std;

int a, b, c, f, k, x;

void output_minus_one_and_terminate_program_and_call_this_is_there_is_an_error_or_use_to_output_no_answer() {
    puts("-1");
    exit(0);
}

int main() {
    scanf("%d%d%d%d", &a, &b, &f, &k);
    x = b - f;
    if (x < 0) output_minus_one_and_terminate_program_and_call_this_is_there_is_an_error_or_use_to_output_no_answer();
    for (int i = 0; i < k; i++) {
        int cst = (i & 1 ? f : a - f) << (i + 1 != k);
        if (x < cst) { 
            if (b < cst) output_minus_one_and_terminate_program_and_call_this_is_there_is_an_error_or_use_to_output_no_answer();
            x = b;
            c++;
        }
        x -= cst;
    }
    printf("%d", c);
    return 0;
}