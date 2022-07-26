#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int n;
    char c[65];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>c; 
        if((c[strlen(c)-1]-'0')%2==0)
            cout<<"even\n";
        else
            cout<<"odd\n";
    }
    return 0;
}