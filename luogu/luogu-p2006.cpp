/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 22:38:32 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 22:38:32 
 */
#include <bits/stdc++.h>
using namespace std;
int k,m,n,a,b;bool flag=false;
int main()
{
    cin>>k>>m>>n;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        (!a||(k/a*b>=n))&&(cout<<i<<" ")&&(flag=true);
    }
    flag||cout<<-1;
    return 0;
}