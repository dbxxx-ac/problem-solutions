#include <iostream>
using namespace std;
int minn=2147483646,n,a[3][2];
int main()
{
    cin>>n;
    for(int i=0;i<3;i++)
        for(int j=0;j<2;j++)
            cin>>a[i][j];
    for(int i=0;i<3;i++)
            minn=min(minn,(((n%a[i][0])==0)?(n/a[i][0]):(n/a[i][0]+1))*a[i][1]);
    cout<<minn;
    return 0;
}