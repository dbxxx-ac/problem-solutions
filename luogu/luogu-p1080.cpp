/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-02-05 00:19:09 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-02-05 01:19:01
 */
#include <bits/stdc++.h>
using namespace std;

int n,m;
const int maxn=1005;
const int maxh=20005;

struct gamer{
    long l,r;
    bool operator<(const gamer a) const{
        return l*r<a.l*a.r;
    }
}gamers[maxn];

string mul(string a,string b){
    int alen=a.size();
    int blen=b.size();
    int res[maxh]={0};
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    for(int i=0;i<alen;i++)
        for(int j=0;j<blen;j++)
            res[i+j]+=(a[i]-'0')*(b[j]-'0');
    for(int i=0;i<alen+blen;i++)
        if(res[i]>=10){
            res[i+1]+=res[i]/10;
            res[i]%=10;
        }

    string ret="";
    bool frontzero=true;
    for(int i=alen+blen-1;i>=0;i--){
        if(!res[i]&&frontzero) continue;
        frontzero=false;
        ret+=res[i]+'0';
    }
    return ret;
}

string div(string a,int b){
    int res[maxh]={0},resa[maxh]={0};
    int len=a.size();
    for(int i=0;i<len;i++)
        res[i+1]=a[i]-'0';
    int tmp=0;
    for(int i=1;i<=len;i++){
        resa[i]=(tmp*10+res[i])/b;
        tmp=(tmp*10+res[i])%b;
    }

    int start=1;
    string ret="";
    while(!resa[start]&&start<len) start++;
    for(int i=start;i<=len;i++)
        ret+=resa[i]+'0';
    return ret;
}

string max(string a,string b){
    if(a.size()!=b.size()) return a.size()>b.size()?a:b;
    return a>b?a:b;
}

string i_to_s(int x){
    string ret="";
    do{
        ret+=x%10+'0';
    }while(x/=10);
    reverse(ret.begin(),ret.end());
    return ret;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
        scanf("%ld%ld",&gamers[i].l,&gamers[i].r);
    sort(gamers+1,gamers+n+1);

    string ans="0";
    string tmp=i_to_s(gamers[0].l);

    for(int i=1;i<=n;i++){
        ans=max(ans,div(tmp,gamers[i].r));
        tmp=mul(tmp,i_to_s(gamers[i].l));
    }

    cout<<ans<<endl;
    return 0;
}