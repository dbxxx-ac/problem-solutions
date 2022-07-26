#include <iostream>
using namespace std;
string group,comet;
int main()
{
    cin>>group>>comet;
    long long groupx=1,cometx=1;
    for(int i=0;i<group.size();i++)
        groupx*=(group[i]-64);
    for(int i=0;i<comet.size();i++)
        cometx*=(comet[i]-64);
    if(groupx%47==cometx%47)
        cout<<"GO";
    else
        cout<<"STAY";
    return 0;
}