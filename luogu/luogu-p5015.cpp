#include <iostream>
#include <cstring>
#include <cstdio>
char s[10];
long long ans;
using namespace std;
int main()
{
    gets(s);
    for(int i=0;i<strlen(s);i++)
        if(s[i]!=' '&&s[i]!='\n')
            ans++;
    printf("%d",ans);
    return 0;
}