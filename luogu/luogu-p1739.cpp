/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 22:04:46 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 22:04:46 
 */
#include <bits/stdc++.h>
using namespace std;
string oper;
int status;
int main()
{
    cin>>oper;
    for(int i=0;i<oper.length();i++)
    {
        if(oper[i]=='(') status++;
        else if(oper[i]==')') status--;
        if(status<0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if(status==0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}