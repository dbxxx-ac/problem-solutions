#include <iostream>
using namespace std;
int main()
{
    int a,b,max=0,day=0;
    for(int i=1;i<=7;i++) 
    {
        cin>>a>>b; 
        if((a+b>max)&&(a+b>8)){max=a+b;day=i;}
    }
    cout<<day;
    return 0;             
}