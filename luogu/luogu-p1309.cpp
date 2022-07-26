/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-02-04 21:57:26 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-02-04 23:17:39
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;

struct competitor{
	int s,w,ind;
	bool operator<(const competitor &a)const{
		if(a.s!=s) return s>a.s;
		return ind<a.ind;
	}
};

competitor a[maxn],loser[maxn],winner[maxn];
int n,r,q;

int main(){
	scanf("%d%d%d",&n,&r,&q);
	for(int i=1;i<=n*2;i++){
		scanf("%d",&a[i].s);
		a[i].ind=i;
	}
	for(int i=1;i<=n*2;i++) scanf("%d",&a[i].w);
	sort(a+1,a+n*2+1);

	while(r--){
		for(int i=1;i<=n;i++){
			if(a[2*i-1].w<a[2*i].w){
				a[2*i].s++;
				winner[i]=a[2*i];
				loser[i]=a[2*i-1];
			}else{
				a[2*i-1].s++;
				winner[i]=a[2*i-1];
				loser[i]=a[2*i];
			}
		}
		merge(loser+1,loser+n+1,winner+1,winner+n+1,a+1);
	}

	printf("%d\n",a[q].ind);
	return 0;
}