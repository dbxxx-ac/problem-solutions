/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 22:39:23 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 22:39:23 
 */
#include <bits/stdc++.h>
using namespace std;
int pri[8],n,win[7];
set<int> num;
int main()
{
    cin>>n;
    for(int i=0;i<7;i++)
        cin>>win[i];
    while(n--)
    {
        num.clear();
        for(int i=0;i<7;i++)
        {
            num.insert(win[i]);
            int a;cin>>a;num.insert(a);
        }
        pri[num.size()-7]++;
    }
    for(int i=0;i<7;i++)
        cout<<pri[i]<<" ";
    return 0;
}