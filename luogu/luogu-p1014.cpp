#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
    int x=0,i,j,n;
    cin>>n;
    for(i=1;i<=1000000;i++)
    {
        if(i%2!=0)
        {
            for(j=1;j<=i;j++)
            {
                x++;
                if(x==n)
                {
                    cout<<(i+1)-j<<"/"<<j<<endl;
                    return 0;
                }
            }
        }
        else
        {
            for(j=i;j>=1;j--)
            {
                x++;
                if(x==n)
                {
                    cout<<(i+1)-j<<"/"<<j<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
