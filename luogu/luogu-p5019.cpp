/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 22:31:36 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 22:31:36 
 */
#include <bits/stdc++.h>
using namespace std;
int a[100005],n;
long long ans;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
        if(a[i]>a[i-1])
            ans+=a[i]-a[i-1];
    cout<<ans+a[0]<<endl;
    return 0;
}