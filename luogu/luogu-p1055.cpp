#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    char a[10];
    scanf("%c-%c%c%c-%c%c%c%c%c-%c",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9]);
    long long ans=0;
    for(int i=0;i<9;i++)
        ans+=(a[i]-48)*(i+1);
    ans%=11;
    if(a[9]-48==ans||(a[9]=='X'&&ans==10))
        cout<<"Right"<<endl;
    else
        printf("%c-%c%c%c-%c%c%c%c%c-%c",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],ans==10?'X':ans+48);
    return 0;
}