#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[102];
int main()
{
    int ans=0;
    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]=='V'&&a[i+1]=='K')
        {
            ans++;
            a[i]='X';
            a[i+1]='X';
        }
    }
    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]!='X'&&a[i]==a[i+1])
        {
            ans++;
            break;
        }
    }
    printf("%d",ans);
    return 0;
}
