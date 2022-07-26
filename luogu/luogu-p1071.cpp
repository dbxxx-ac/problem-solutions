/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 22:02:49 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 22:02:49 
 */
#include <bits/stdc++.h>
using namespace std;
string x,y,z;
int c[27],s=0;
bool a[27],b[27];
int main()
{
    cin>>x>>y>>z;
    for(int i=0;i<x.size();++i)
    {
        if(!a[x[i]-'A'+1]&&!b[y[i]-'A'+1])
        {
            c[x[i]-'A'+1]=y[i];
            a[x[i]-'A'+1]=b[y[i]-'A'+1]=true;
            s++;
        }    
        else if(c[x[i]-'A'+1]!=y[i])
        {
            cout<<"Failed";
            return 0;    
        }
    }
    if(s!=26)
    {
        cout<<"Failed";
            return 0;    
    }
    for(int i=0;i<z.size();++i)
    {
        printf("%c",c[z[i]-'A'+1]);    
    }
}    