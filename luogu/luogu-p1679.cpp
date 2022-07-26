#include<iostream>
using namespace std;
int a[100005],s[25];
int cal4(int i)
{
    return i*i*i*i;
}
int main()
{
    int m;
    for(int i=1;i<18;i++)
        s[i]=cal4(i);
    cin>>m;
    for(int i=1;i<=m;i++) a[i]=i;
    for(int i=2;i<=17;i++)
        for(int j=s[i];j<=m;j++)
            a[j]=min(a[j],a[j-s[i]]+1);
    cout<<a[m]<<endl;
}
