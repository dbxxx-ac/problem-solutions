#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    char st1[105],st2[105];
    scanf("%d%s%s",&n,st1,st2);
    for(int i=0;i<n;i++) 
        if(st2[i]>st1[i])
        {
            puts("-1");
            return 0;
        }
    puts(st2);
    return 0;
}