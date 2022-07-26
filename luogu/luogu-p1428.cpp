#include <iostream>
using namespace std;
int a[101],s[101],n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=i;j>=1;j--)
        {
            if(a[j]<a[i])
                s[i]++;
        }
    for(int i=1;i<=n;i++) cout<<s[i]<<" ";
    return 0;
}