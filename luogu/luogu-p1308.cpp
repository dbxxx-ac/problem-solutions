#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a;
    string b;
    getline(cin,a);
    getline(cin,b);
    for(int i=0;i<a.length();++i)
        a[i]=tolower(a[i]);
    for(int i=0;i<b.length();++i)
        b[i]=tolower(b[i]);
    a=' '+a+' ';
    b=' '+b+' ';
    if(b.find(a)==string::npos)
        cout<<-1<<endl;
    else
    {
        int a1=b.find(a);
        int b1=b.find(a),s=0;
        while(b1!=string::npos)
        {
            s++;
            b1=b.find(a,b1+1);
        }
        cout<<s<<" "<<a1<<endl;
    }
    return 0;
}