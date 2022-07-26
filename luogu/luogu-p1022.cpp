#include <bits/stdc++.h>
using namespace std;
int vari1,vari2,cons1,cons2,thisnum;
string equ,thisstr;
char p;
bool flag=true,pom=true;
int main()
{
    cin>>equ;
    for(int i=0;i<equ.length();i++)
    {
        if(equ[i]>='0'&&equ[i]<='9') thisstr+=equ[i];
        else if(equ[i-1]>='0'&&equ[i-1]<='9')
        {
            thisnum=atoi(thisstr.c_str());
            thisstr.clear();
            if(equ[i]<'a'||equ[i]>'z')
                (flag?cons1:cons2)+=(pom?thisnum:-thisnum);
        }
        if(equ[i]=='+') pom=true;
        if(equ[i]=='-') pom=false;
        if(equ[i]>='a'&&equ[i]<='z')
        {
            p=equ[i];
            int now;
            if(equ[i-1]<'0'||equ[i-1]>'9')
                now=1;
            else now=thisnum;
            (flag?vari1:vari2)+=(pom?now:-now);
        }
        if(equ[i]=='=') {flag=false;pom=true;}
    }
    cons2+=pom?atoi(thisstr.c_str()):-atoi(thisstr.c_str());
    double ans;
    ans=double(cons1-cons2)/(vari2-vari1);
    cout<<p<<"="<<setprecision(3)<<fixed<<ans;
    return 0;
}