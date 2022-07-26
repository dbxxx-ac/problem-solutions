#include <iostream>
using namespace std;
int city[102][102][2];
int x,y,x1,y1,x2,y2;
int main()
{
    cin>>x1>>y1>>x>>y;
    for(int k=1;k<=x;k++)
    {
        cin>>x1>>y1>>x2>>y2;
        for(int i=x1;i<=x2;i++)
            for(int j=y1;j<=y2;j++)
                city[i][j][0]=k,city[i][j][1]++;
    }
    for(int i=1;i<=y;i++)
    {
        cin>>x2>>y2;
        if(city[x2][y2][0]==0) cout<<'N'<<endl;
        else cout<<'Y'<<" "<<city[x2][y2][1]<<" "<<city[x2][y2][0]<<endl;
    }
    return 0;
}