#include<bits/stdc++.h>
using namespace std;
bool f;
int main()
{
    int k;
    cin>>k;
    for(int i=10000;i<=30000;i++)
    {
        if(i/100%k==0&&((i/10-i/10000*1000)%k==0)&&((i-i/1000*1000)%k==0)) 
        {
            cout<<i<<endl;
            f=true;
        }
    }
    if(!f) cout<<"No";
    return 0;
}