#include<iostream>
#include<algorithm>
using namespace std;
struct road
{
    int n,p;
}k[1005],l[1005];

bool cmp(road x,road y)
{
    return x.n>y.n;
}
bool cmp1(road x,road y)
{
    return x.p<y.p;
}
int min(int a,int b)
{
    return a<b?a:b;
}
int d,n,m,k1,l1,x1,x2,y1,y2;
int main()
{
    cin>>m>>n>>k1>>l1>>d;
    for(int i=1;i<=d;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        if(x1==x2) 
        {
            l[min(y1,y2)].p=min(y1,y2);
            l[min(y1,y2)].n++;
        }
        else 
        {
            k[min(x1,x2)].p=min(x1,x2);
            k[min(x1,x2)].n++;
        }
    }
    sort(l+1,l+n+1,cmp);
    sort(k+1,k+m+1,cmp);
        sort(k+1,k+k1+1,cmp1);
    sort(l+1,l+l1+1,cmp1);
    for(int i=1;i<=k1;i++) cout<<k[i].p<<" ";
    cout<<endl;
    for(int i=1;i<=l1;i++) cout<<l[i].p<<" ";
    return 0;
}