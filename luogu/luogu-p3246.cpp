#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#define maxn 100010
using namespace std;
int n,m;
int val[maxn],f[maxn][30],front[maxn],nxt[maxn];
long long ans[maxn],maxl[maxn],maxr[maxn];
struct node{
	int l,r,id;
}que[maxn];
struct Stack
{
    int value[maxn],numtop;
    Stack()
    {
        memset(value,0,sizeof(value));
        numtop=0;
    }
    inline void push(int x){value[++numtop]=x;}
    inline void pop(){value[numtop--]=0;}
    inline int top(){return value[numtop];}
    inline int empty(){return (numtop==0?1:0);}
}stack;
inline int read(){
	int date=0,w=1;char c=0;
	while(c<'0'||c>'9'){if(c=='-')w=-1;c=getchar();}
	while(c>='0'&&c<='9'){date=date*10+c-'0';c=getchar();}
	return date*w;
}
bool cmp1(const node &x,const node &y){
	return x.l<y.l;
}
bool cmp2(const node &x,const node &y){
	if(x.r==y.r)return x.l<y.l;
	return x.r<y.r;
}
void step(){
    for(int i=1;(1<<i)<=n;i++)
    for(int j=1;j+(1<<i)-1<=n;j++)
    {
    	if(val[f[j][i-1]]>val[f[j+(1<<(i-1))][i-1]])f[j][i]=f[j+(1<<(i-1))][i-1];
    	else f[j][i]=f[j][i-1];
    }
}
int query(int l,int r){
    int k=0;
    while((1<<(k+1))<=r-l+1)k++;
	if(val[f[l][k]]>val[f[r-(1<<k)+1][k]])return f[r-(1<<k)+1][k];
    return f[l][k];
}
void work(){
    int left=1,right=0;
	long long s=0;
	for(int i=1;i<=m;i++){
		while(right<que[i].r)
		{
			right++;
			int pos=query(left,right);
			s+=(long long)val[pos]*(pos-left+1)+maxl[right]-maxl[pos];
		}
		while(que[i].l>left)
		{
			int pos=query(left,right);
			s-=(long long)val[pos]*(right-pos+1)+maxr[left]-maxr[pos];
			left++;
		}
		while(right>que[i].r)
		{
			int pos=query(left,right);
			s-=(long long)val[pos]*(pos-left+1)+maxl[right]-maxl[pos];
			right--;
		}
		while(que[i].l<left)
		{
			left--;
		    int pos=query(left,right);
		    s+=(long long)val[pos]*(right-pos+1)+maxr[left]-maxr[pos];
		}
		ans[que[i].id]=s;
	}
	for(int i=1;i<=m;i++)printf("%lld\n",ans[i]);
}
void init()
{
	int nowi=1,nowj=0,d,x;
    n=read();m=read();
    for(int i=1;i<=n;i++)
    {
        val[i]=read();
        f[i][0]=i;
    }
    step();
	for(int i=1;i<=m;i++)
	{
		que[i].l=read();que[i].r=read();
		que[i].id=i;
	}
	x=sqrt(n);
	sort(que+1,que+m+1,cmp1);
	while(nowi<=m)
	{
		nowj++;
		d=nowi;
		while(que[nowi].l<nowj*x&&nowi<=m)nowi++;
		sort(que+d,que+nowi,cmp2);
		if(nowj==x)
		{
			sort(que+d,que+m+1,cmp2);
			break;
		}
	}
	for(int i=1;i<=n;i++){
	    for(;!stack.empty()&&val[i]<val[stack.top()];stack.pop())nxt[stack.top()]=i;
	    front[i]=stack.top();
	    stack.push(i);
	}
	for(;!stack.empty();stack.pop())nxt[stack.top()]=n+1;
	for(int i=1;i<=n;i++)maxl[i]=maxl[front[i]]+(long long)val[i]*(i-front[i]);
	for(int i=n;i>=1;i--)maxr[i]=maxr[nxt[i]]+(long long)val[i]*(nxt[i]-i);
}
int main()
{
    init();
    work();
	return 0;
}
