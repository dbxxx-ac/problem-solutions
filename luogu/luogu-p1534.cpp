#include <iostream>
#include <cstdio>
using namespace std;
long long n,a,b,h,j;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        j=j+a+b-8;
        h+=j;
    }
    cout<<h;
    return 0;
}
