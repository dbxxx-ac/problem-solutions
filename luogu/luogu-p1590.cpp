/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 21:56:49 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 21:56:49 
 */
#include <bits/stdc++.h>
using namespace std;
long long n,T,ans,atr;
int main()
{
    cin>>T;
    while(T--){
        for(atr=1,ans=0,scanf("%lld",&n);n;n/=10,atr*=9)
            ans+=atr*(n%10)-(n%10>=7?atr:0);
        cout<<ans<<endl;
    }
}