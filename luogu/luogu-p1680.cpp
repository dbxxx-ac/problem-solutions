#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

long long n,m,MOD=1e9+7;

long long qm(long long a,long long b)
{
    long long ans=1;
    a%=MOD;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%MOD;
            b--;
        }
        b/=2;
        a=a*a%MOD;
    }
    return ans;
}

long long combin(long long n,long long m)
{
    if(m>n) return 0;
    long long ans = 1;
    for(int i=1;i<=m;i++)
    {
        long long a=(n+i-m)%MOD;
        long long b=i%MOD;
        ans=ans*(a*qm(b,MOD-2)%MOD)%MOD;
    }
    return ans;
}

long long lucas(long long n,long long m)
{
    if(!m) return 1;
    return combin(n%MOD,m%MOD)*lucas(n/MOD,m/MOD)%MOD;
}

int main()
{
    long long sum,x;
    scanf("%lld%lld",&n,&m);
    sum=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&x);
        sum+=x;
    }
    if(n-sum-1<=0)
    {
        printf("0\n");
    }
    else
        printf("%lld\n", lucas(n-sum-1,m-1));
    return 0;
}
