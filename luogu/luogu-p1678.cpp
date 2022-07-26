#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int a[100100],b[100100];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        int l=0,r=n+1;
        while(l<r)
        {
            int mid=(l+r)/2;
            a[mid]<=b[i]?l=mid+1:r=mid;
        }
        if(b[i]<=a[1])
            ans+=a[1]-b[i];
        else
            ans+=min(abs(a[l-1]-b[i]),abs(a[l]-b[i]));
    }
    cout<<ans;
    return 0;
}
