#include <iostream>
#include <cstdio>
using namespace std;

long long W[25][25][25],x,y,z;

int w(long long a,long long b,long long c)
{
    if(a<=0||b<=0||c<=0) return 1;
    if(a>20||b>20||c>20) a=b=c=20;
    if(W[a][b][c]) return W[a][b][c];
    if(a<b&&b<c) return W[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    return W[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}

int main() 
{
    while(cin>>x>>y>>z&&(x!=-1||y!=-1||z!=-1))
        printf("w(%lld, %lld, %lld) = %d\n",x,y,z,w(x,y,z));
}