/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 21:57:59 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 21:57:59 
 */
#include <bits/stdc++.h>
using namespace std;
bool flip[105];
int n;
int main()
{
    cin>>n;
    cout<<n<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j) flip[j]=!flip[j];
            cout<<int(flip[j]);
        }
        cout<<endl;
    }
}