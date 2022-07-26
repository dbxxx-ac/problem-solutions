/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 22:31:06 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 22:31:06 
 */
#include <bits/stdc++.h>
using namespace std;
double n,x,a,life=10,expe;
int main()
{
    cin>>n;//输入
    while(n--)
    {
        cin>>x>>a;
        life-=x;
        if(life>10) life=10;
        if(life<=0) //cout<<"Game over!!!!!"<<endl;
            break;
        expe+=a;
    }
    for(n=0;expe>=pow(2,n+1)-1;n++)
        a=expe-pow(2,n+1)+1;
    cout<<n<<' '<<a<<endl;
    return 0;
}