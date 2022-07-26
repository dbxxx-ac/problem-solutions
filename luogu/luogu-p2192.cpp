#include <iostream>
using namespace std;
int n,x,t5,t0;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x==5)
            t5++;
        else
            t0++;
    }
    if(!t0)
        cout<<-1;
    else
    {
        if(t5>=9)
        {
            for(int i=1;i<=t5/9*9;i++)
                cout<<5;
            for(int i=1;i<=t0;i++)
                cout<<0;
        }
        else
            cout<<0;
    }
    return 0;
}