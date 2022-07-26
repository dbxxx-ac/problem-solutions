/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 22:04:20 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 22:04:20 
 */
#include <bits/stdc++.h>
using namespace std;
long long n,m,squ,rec;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(i==j)
                squ+=(n-i+1)*(m-j+1);
            else
                rec+=(n-i+1)*(m-j+1);
    cout<<squ<<' '<<rec<<endl;
    return 0;
}