#include <iostream>
using namespace std;
int n,a[100001];
long long ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=2;i<=n;i++)
        ans+=max(a[i],a[i-1]); 
    cout<<ans; 
    return 0;
}