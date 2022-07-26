#include <iostream>
#include <cmath>
using namespace std;
int a;
bool prime(int x)
{
    for(int i=2;i<=sqrt(x);i++)
        if(x%i==0)
            return false;
    return true;
}
int main()
{
    cin>>a;
    for(int i=2;i<=a-4;i++)
        for(int j=2;j<=a-4;j++)
        {
            int k=a-i-j;
            if(prime(i)&&prime(j)&&prime(k))
            {
                cout<<i<<' '<<j<<' '<<k;
                return 0;
            }
        }
}