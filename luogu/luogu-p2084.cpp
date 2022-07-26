#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    int i,ja,j;
    char n[1005];
    scanf("%d%s",&ja,n);
    for(i=0,j=strlen(n)-1;i<strlen(n);i++,j--)
    {
        if(n[i]=='0') continue;
        if(i!=0) printf("+");
        printf("%c*%d^%d",n[i],ja,j);
    }
    return 0;
}