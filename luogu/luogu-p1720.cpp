#include <iostream>
using namespace std;
long long a=1,b=1,tmp=0;
int n;
int main()
{
    cin>>n;
    for(int i=3;i<=n;i++)
    {
        tmp=a+b;
        a=b;
        b=tmp;
    }
    cout<<tmp<<".00";
    return 0;
}