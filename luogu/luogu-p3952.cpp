/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-02-01 18:49:43 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-02-01 19:16:32
 */
#include <bits/stdc++.h>
using namespace std;

int n,m,t,len;
string o;
string code[105];

int max(int a,int b){
    return a>b?a:b;
}

int getnum(int &chgind,string s){
    int ret=0;
    int len=s.length();

    while(s[chgind]<'0'||s[chgind]>'9'&&chgind<len){
        if(s[chgind]=='n'){
            chgind++;
            return 1000000;
        }
        chgind++;
    }

    while(s[chgind]>='0'&&s[chgind]<='9'){
        ret=ret*10+s[chgind]-'0';
        chgind++;
    }

    return ret;
}

int geto(){
    int chgind=3;
    if(o[2]=='n') return getnum(chgind,o);
    return 0; 
}

int cal(){
    int ret=0,now=0,flag=-10086;
    stack<int> s;
    bool vis[35]={0};
    bool bonus[35]={0};
    for(int i=1;i<=len;i++){
        if(code[i][0]=='F'){
            int var=code[i][2]-'a';
            if(vis[var]) return -10086;
            s.push(var);
            vis[var]=true;
            //int chgind=3;
            int chgind=4;
            int fr=getnum(chgind,code[i]);
            int to=getnum(chgind,code[i]);
            //printf("%d %d\n",fr,to);
            if(flag==-10086){
                if(fr>to) flag=var;
                if(to>fr+1000){
                    now++;
                    ret=max(ret,now);
                    bonus[var]=true;
                }
            }
        }else if(code[i][0]='E'){
            if(s.empty()) return -10086;
            int var=s.top();
            //printf("%d\n",var);
            s.pop();
            vis[var]=false;
            if(flag==var) flag=-10086;
            if(bonus[var]){
                bonus[var]=false;
                now--;
            }
        }
    }
    if(!s.empty()) return -10086;
    return ret;
}

int main(){
    scanf("%d",&t);
    //cin>>o;
    //printf("%d\n",geto());
    while(t--){
        scanf("%d ",&len);
        getline(cin,o);
        for(int i=1;i<=len;i++)
            getline(cin,code[i]);
        if(cal()==-10086) puts("ERR");
        else if(cal()==geto()) puts("Yes");
        else puts("No");
        //printf("%d %d\n",geto(),cal());
    }
    return 0;
}