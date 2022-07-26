#include<iostream>
using namespace std;
int main()
{
    long a,b,c;
    cin>>a>>b>>c;
    long maxn=-100000000,minn=100000000;
    if(a>maxn) maxn=a;
    if(a<minn) minn=a;
    if(b>maxn) maxn=b;
    if(b<minn) minn=b;
    if(c>maxn) maxn=c;
    if(c<minn) minn=c;
    int div;
    for(int i=minn;i>=1;i--)
    if(maxn%i==0&&minn%i==0)
    {
        div=i;
        break;
    } 
    maxn/=div;
    minn/=div;
    cout<<minn<<'/'<<maxn<<endl;
    return 0;
}