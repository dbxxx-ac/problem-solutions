#include <iostream>
using namespace std;
int x;
long long n;
int main()
{
    cin>>x>>n;
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        if(x==6||x==7)
        {
            x++;
            continue;
        }
        sum+=250;
        x++;
        x%=7;
    }
    cout<<sum;
    return 0;
}