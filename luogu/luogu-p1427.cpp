#include <iostream>
using namespace std;
int s[100],top=0;
int main()
{
    do
    {
        cin>>s[++top];
    }while(s[top]!=0);
    while(top-1)
        cout<<s[--top]<<" ";
    return 0;
}