#include <iostream>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int x=c-a;
    int y=d-b;
    if(y<0)
    {
        x--;
        y+=60;
    }
    cout<<x<<" "<<y;
    return 0;
}