/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 22:37:23 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 22:37:23 
 */
#include <bits/stdc++.h>
using namespace std;
char s;
int n;
bool flag;
int main()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            cin>>s;
            if(s!='-')
            {
                n++;
                if(s=='X'&&abs(i-j)==1) flag=true;
            }
        }
    flag?cout<<"xiaoa will win.\n":cout<<"Dont know.\n";
    cout<<n;
    return 0;
}