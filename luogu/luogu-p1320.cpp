#include <iostream>
#include <climits>
using namespace std;
string now;
char lastlet;
int len=INT_MAX,ans=0;
int main()
{
    for(int i=0;i<len;i++)
    {
        cin>>now;
        len=now.size();
        if(!i){cout<<len<<" ";lastlet=now[0];if(now[0]=='1') cout<<"0"<<" ";}
        for(int j=0;j<len;j++)
            if((!j&&now[j]!=lastlet)||(j&&now[j]!=now[j-1]))
                cout<<ans<<" ",ans=1;
            else
                ans++;
        lastlet=now[len-1];
    }
    cout<<ans;
    return 0;
}