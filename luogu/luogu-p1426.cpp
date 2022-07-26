#include <iostream>
#include <cmath>
using namespace std;
double speed=7,s,x,l,r,now;
int main()
{
    cin>>s>>x; 
    l=s-x; 
    r=s+x;
    while(1)
    {
        if(now>r)
        {
            cout<<"n"; 
            break;
        }
        if (l<=now&&now<=r)
        {
            if (now+speed>r)
            {
                cout<<"n"; 
                break;
            }
            else
            {
                cout<<"y";
                break; 
            }
        }
        now+=speed; 
        speed*=0.98;
    }
}