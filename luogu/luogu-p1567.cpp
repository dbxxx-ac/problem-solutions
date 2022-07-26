#include <iostream>
using namespace std;
int a[10000005],n,t,g=1;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>a[i-1])
            g++;
        else
        {
            t=max(t,g);
            g=1;
        }
    }
    cout<<t;
    return 0;
}