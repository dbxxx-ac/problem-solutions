#include<iostream>
#include<algorithm> 
using namespace std;
int n,s,a,b,x,y,can,ans;
struct ap
{
    int xi,yi;
}apple[50005];
bool cmp(ap x,ap y){
    return x.yi<y.yi;
}
int main()
{
    cin>>n>>s>>a>>b;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        if(x<=a+b)
        {
            can++;
            apple[can].xi=x;
            apple[can].yi=y;
        }
    }
    sort(apple+1,apple+can+1,cmp);
    for(int i=1;s>=apple[i].yi&&i<=can;i++)
    {
        ans++;
        s-=apple[i].yi;
    }
    cout<<ans;
    return 0;
}