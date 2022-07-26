/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 22:34:37 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 22:34:37 
 */
#include <bits/stdc++.h>
using namespace std;
int r,n,m,x,y,ans;
bool ground[105][105];
int main()
{
    cin>>n>>m>>r;
    while(m--)
    {
        cin>>x>>y;
        for(int i=max(x-r,1);i<=x+r&&i<=n;i++)
            for(int j=max(y-r,1);j<=y+r&&j<=n;j++)
                if(sqrt((i-x)*(i-x)+(j-y)*(j-y))<=r)
                    ground[i][j]=true;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(ground[i][j])
                ans++;
    cout<<ans<<endl;
    return 0;
}