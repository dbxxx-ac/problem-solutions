#include <iostream>
using namespace std;
int money,cost,mom,flag=1,month;
int main()
{
    for(int i=1;i<=12;i++)
    {
        money+=300; 
        cin>>cost;
        money-=cost;
        if(money<0)
        {     
            flag=0;
            month=i;
            break;
        }
        mom+=money/100;
        money%=100;        
    }    
    if(flag==1)
    {
        money+=mom*120;
        cout<<money;
    }            
    else
        cout<<-month;
    return 0;
}