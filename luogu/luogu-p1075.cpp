/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 21:58:34 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-01-10 22:00:14
 */
#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    cin>>n;
    for(int i=2;i<=sqrt(n);i++)
        if(!(n%i))
            cout<<n/i<<endl;
    return 0;
}