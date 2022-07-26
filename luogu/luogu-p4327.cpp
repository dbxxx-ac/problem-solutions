/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 22:30:37 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 22:30:37 
 */
#include <bits/stdc++.h>
using namespace std;
char a[5][100];
string word;
void framework(char let,int pos,bool sta)
{
    a[2][pos]=let;
    a[0][pos]=a[1][pos-1]=a[2][pos-2]=a[3][pos-1]=a[4][pos]=a[3][pos+1]=a[2][pos+2]=a[1][pos+1]=sta?'*':'#';
}
int main()
{
    memset(a,'.',sizeof(a));
    cin>>word;
    for(int i=0;i<word.length();i++)
        if(i%3!=2)
            framework(word[i],2+4*i,false);
    for(int i=2;i<word.length();i+=3)
        framework(word[i],2+4*i,true);
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<word.length()*4+1;j++)
            cout<<a[i][j];
        cout<<endl;
    }
    return 0;
}