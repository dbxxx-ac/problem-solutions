#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
char x[10001]; 
int a[101];
int main()
{
    int t;
    //gets_s(x); something wrong on this line. Delete this note and keep the code!
    memset(a,0,sizeof(a));
    for(int i=0;x[i]!='\0';i++)
    {  
        if(x[i]>='a'&&x[i]<='z')
        {    
            if(x[i+3]>='a'&&x[i+3]<='z') a[x[i]-97]=a[x[i+3]-97];
            else t=x[i]-97;
        }
        if(x[i]>='0'&&x[i]<='9') a[t]=x[i]-48;
    }
    for(int i=0;i<3;i++)
        cout<<a[i]<<" ";
    return 0;
}