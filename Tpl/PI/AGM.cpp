#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
// AGM π计算程序
double a[1000];
double x[100];
double b[10000];
double c[10000];
double y[1000];
double g=0;
int j;
double *ad;
double *xd;
double *bd;
double *cd;
double *yd;
cout<<"您希望本程序算π小数点后几位:"; 
cin>>j; //接受计算位数
if(j<=0)
{
cout<<"\a"<<"输入的数不能为0 ";
cout<<"您希望本程序算π小数点后几位:";
cin>>j; //接受计算位数
}
else
{

}
j=j+2; //由于是小数点后几位所以加2
const int p=1; //定义常量保证程序不出错
//初值：
a[1000]=x[100]=1; 
b[10000]=sqrt(2)/2; 
c[1000]=0.25;
//给指针赋值:
ad = &a[1000];
xd = &x[100];
bd = &b[10000];
cd = &c[10000];
//重复计算
while (g<=1000000)
{
y[1000]=a[1000];
yd=&y[1000];
a[1000]=(*ad + *bd)/2;
b[10000]=sqrt(*bd * *yd);
c[10000]=*cd - *xd * (*ad - *yd) * (*ad - *yd);
x[100]=*xd * 2;
g++;
}
double PI[p]; //π
PI[p]=(*ad + *bd) * (*ad + *bd) / (4 * *cd);
// cout<<"π=";
cout<<PI[p];
cout<<endl;
return 0;
}