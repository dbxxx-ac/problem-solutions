//luoguP8338
//remake.
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define int long long
#define mk make_pair
using namespace std;
const int maxn=5e5+10;
const int mod=1e9+7;
int a[maxn],fa[maxn];//a 表示输入序列，fa 表示并查集上每个点的祖先。 
int vis[maxn],p[maxn];//vis 存储的是每个数的最小质因子，p 存储的是 5e5 内的质因子。
int pcnt[maxn];//pcnt 用来存储每个数有多少个质因子。 
int sz[maxn],c[maxn];//sz 用来存储每一个环的大小，c 用来记录每一个环长有多少个。 
int huan[maxn];//环长集合。
int inv[maxn],cntp[maxn];//计数器 
int cnt,ans,lcm; 
 
vector<pair<int,int> >pri[maxn],g[maxn];
//pri 存储每个数的具体质因子(first)以及幂(second)，g 是个临时动态数组，存储的是当前这个数被删/加了多少次。
vector<int>f[maxn];//f 表示的是每个质因子有哪些幂。 

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int cmp(int a,int b){return a>b;}

void init()
{
	inv[0]=inv[1]=1;
	for(int i=2;i<=500000;i++)inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	int cnt=0;
	for(int i=2;i<=500000;i++)
	{
		if(!vis[i]){vis[i]=i;p[++cnt]=i;}
		for(int j=1;j<=cnt&&i*p[j]<=500000;j++)
		{
			if(p[j]>vis[i])break;
			vis[i*p[j]]=p[j];
		}
	}
	for(int i=2;i<=500000;i++)
	{
		int t=i;
		while(t>1)
		{
			int now=vis[t];
			int val=1;
			while(!(t%now))
			{
				val*=now;
				t/=now;
			}
			pri[i].push_back(mk(now,val));
		}
	}
}

int find(int x)
{
	if(x!=fa[x])fa[x]=find(fa[x]);
	return fa[x];
}

void add(int x,int y)
{
	x=find(x);y=find(y);
	if(x==y)return ;
	if(sz[x]>sz[y])swap(x,y);//启发式合并。 
	fa[x]=y;
	sz[y]+=sz[x]; 
}

void insert(int x)
{
	for(auto y:pri[x])
	{
		int p=y.first,q=y.second;
		f[p].push_back(q);
		sort(f[p].begin(),f[p].end(),cmp);
		if(f[p].size()>3)f[p].pop_back(); 
	}
	return ;
}

int get(int x)
{
	int ret=1;
	for(int y:f[x])cntp[y]++;
	for(auto y:g[x])cntp[y.first]+=y.second;
	for(int y:f[x])
	{
		if(cntp[y])ret=max(ret,y),cntp[y]=0;
	}
	for(auto y:g[x])
	{
		if(cntp[y.first])ret=max(ret,y.first),cntp[y.first]=0;
	}
	return ret;
}

void upd(int x,int num)
{
	for(auto y:pri[x])
	{
		int p=y.first,q=y.second;
		(lcm*=inv[get(p)])%=mod;
		g[p].push_back(mk(q,num));
		(lcm*=get(p))%=mod;
	}
}

void clearg(int x)
{
	for(auto y:pri[x])g[y.first].clear();
}

signed main()
{
	init();//预处理 1-n 每个数的质因子。（nlogn 分解质因数） 
	int T=read();
	while(T--)
	{
		ans=0;
		int n;
		n=read();
		memset(c,0,sizeof(c));
		memset(huan,0,sizeof(huan));
		for(int i=1;i<=n;i++)f[i].clear();
		for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;//初始化 fa 数组。 
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			add(i,a[i]);//每次将 i 与 a[i] 连边（合并） 
		}
		cnt=0;//cnt 表示的是有多少种不同的环长。 
		for(int i=1;i<=n;i++)
		{
			if(fa[i]==i)//如果它本身就是祖先。 
			{
				if(!c[sz[i]])//原先环长集合中没有这个数，则将其加入环长集合。 
				{
					huan[++cnt]=sz[i]; 
				}
				c[sz[i]]++;
			    insert(sz[i]);
			}
		 } 
		//初始化 lcm
		lcm=1; 
		for(int i=1;i<=n;i++)
		{
			if(f[i].empty())continue;
			(lcm*=f[i][0])%=mod;
		 } 
		//i=j 的情况。 
		for(int i=1;i<=cnt;i++)
		{
			// printf("%lld ", huan[i]);
			if(c[huan[i]]<=1)continue;
			int tt=lcm;
			upd(huan[i]+huan[i],1);
			upd(huan[i],-2);
			(ans+=lcm*huan[i]%mod*c[huan[i]]%mod*(c[huan[i]]-1)%mod*(huan[i])%mod)%=mod;
			// printf("%lld\n", lcm);
			clearg(huan[i]+huan[i]);
			lcm=tt;
		}
		for(int i=1;i<=cnt;i++)
		{
			for(int j=i+1;j<=cnt;j++)
			{
				// printf("%lld %lld\n", huan[i], huan[j]);
				int tt=lcm;
				upd(huan[i]+huan[j],1);
				upd(huan[i],-1);
				upd(huan[j],-1);
				(ans+=2*lcm%mod*huan[i]%mod*c[huan[i]]%mod*c[huan[j]]%mod*huan[j]%mod)%=mod;
				clearg(huan[i]+huan[j]);
				clearg(huan[i]);clearg(huan[j]);
				// printf("%lld\n", lcm);
				lcm=tt;
			}
		 } 
		cout<<ans<<endl;
	}
}
/*重新梳理一下写题思路：
- 首先，预处理出来 1-5e5 范围内所有的数的质因子，具体做法：
  - 先用欧拉筛跑一遍把 1-5e5 范围内的所有质因子预处理出来；
  - 再枚举 1-5e5，然后每次除以这个数的最小质因子然后处理出来这个数所有的质因子。
- 其次，处理每一组数据，对于每一组输入的数据，让 i 与 a[i] 连边，
  实际上只需要在并查集中直接将它们俩直接合并，并维护一下合并后的集合的大小，
  这里为了更加优雅也降低时限，可以采用启发式合并处理集合大小。
- 然后处理出来所有的环长。
- 然后枚举每一个环长，直接把每一次得到的答案并入总答案中，具体处理方法如下：
  - 假设每一个环长的答案是 tt。那么对于每一次枚举的环长 i 和 j：
    - 若 i=j：则答案累加 sz[i]*c[i]*(c[i]-1)*sz[i]*tt;
    - 若 i!=j：则答案累加 sz[i]*c[i]*sz[j]*c[j]*tt; 
  - 现在考虑每一个 tt 如何求：
    首先要维护一个原来的所有环长的 lcm 集合，对于一个质因子 i 维护它的幂 j，可以用 pair 来实现。 
    并且只需要维护对于每一个质因子 i 而言它的前 3 大幂即可。 
    假设每次删除的是 i 和 j，那么每次从 lcm 集合中删除 i 和 j 一个 i 和 j 对应质因数的幂，
	如果这个幂不在质因子对应的前 3 大集合里面可以直接将它忽略。
	然后再插入一个 i+j，同理将 i+j 对应质因子的幂加入集合里。
*/
