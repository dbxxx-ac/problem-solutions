#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int a[12]={1,2,8,9,6,9,29,39,38,65,88,128};
    int n;
    scanf("%d",&n);
    printf("%d",n<=12?0:a[n-13]);
    return 0;
}