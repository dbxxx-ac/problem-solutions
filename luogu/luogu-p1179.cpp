#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char num[7];
int l,r,ans;
int main()
{
    cin>>l>>r;
    for(int i=l;i<=r;i++)
    {
        sprintf(num,"%d",i);
        for(int j=0;j<=strlen(num)-1;j++)
            ans+=(num[j]=='2');
    }
    cout<<ans;
    return 0;
}