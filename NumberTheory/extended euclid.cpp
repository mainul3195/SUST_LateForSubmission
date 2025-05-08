#include <bits/stdc++.h>
using namespace std;int x, y;
int gcdExtended(int a, int b, int *x, int *y) {
if (b==0) {*x = 1;*y = 0;return a;}
int x1, y1;int gcd = gcdExtended(b,a%b,&x1,&y1);
*x =y1;*y =x1-y1*(a/b);return gcd;}
int main() { int a = 50, b = 10;
cout<<"gcd "<<gcdExtended(a, b, &x, &y)<<endl;;
cout<<x<<" " <<y<<endl;return 0;}
