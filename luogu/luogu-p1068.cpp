#include <bits/stdc++.h>
using namespace std;
struct people
{
    int num,score;
}a[5005];
bool cmp(people a,people b)
{
    return a.score==b.score?(a.num<b.num):(a.score>b.score);
}
int n,m,ans2,ansx,ans;
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i].num>>a[i].score;
    sort(a,a+n,cmp);
    for(int i=0;ansx<int(m*1.5);i++)
    {
        if(a[i].score==ans) continue;
        ans2=a[i].score;
        ansx++;
    }
    for(int i=0;a[i].score>=ans2;i++)
        ans++;
    cout<<ans2<<" "<<ans<<endl;
    for(int i=0;a[i].score>=ans2;i++)
        cout<<a[i].num<<" "<<a[i].score<<endl;
    return 0;
}
