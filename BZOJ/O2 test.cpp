//#include <stdio.h>
//int main() {
//int a = -1;
//for(int i=1;i<200000;++i) a += i;
//while(a < 0) {
//puts("wa");
//}
//printf("%d\n", a, a < 0);
//}
//



#include <stdio.h>
int main() {
int a = -1;
for(int i=1;i<200000;++i) a += i;

printf("%d\n", a, a < 0);

while(a < 0) {
puts("wa");
}
}
