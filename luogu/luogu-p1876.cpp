#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cout<<1;
    for(int i=2;i<=sqrt(n);i++)
        cout<<" "<<i*i;
    return 0;
}