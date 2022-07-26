#include <bits/stdc++.h>
using namespace std;

int c,x,m,n,d;
int price[100005];
double minans=-1e9;
double maxans=1e9;

double min(double a,double b){
    return a<b?a:b;
}

double max(double a,double b){
    return a>b?a:b;
}

int main(){
    int p=0;
    scanf("%d%d%d",&x,&c,&n);
    m=c;
    while(m!=-1&&n!=-1){
        price[m]=n;
        for(int i=p+1;i<m;i++)
            price[i]=price[i-1]+(n-price[p])/(m-p);
        p=m;
        scanf("%d%d",&m,&n);
    }
    scanf("%d",&d);
    //printf("%d\n",1);
    //for(;price[p]>d;p++) price[p]=price[p-1]-d;
    while(price[p]>d) p++,price[p]=price[p-1]-d;
    /*
    for(int i=1;i<=40;i++)
        printf("%d ",price[i]);
    printf("\n");
    */
    for(int i=c;i<=p;i++){
        double tmp=(price[x]*(x-c)-price[i]*(i-c))*1.0/(price[i]-price[x]);
        double f=price[i]-price[x];
        if(f>0) maxans=min(tmp,maxans);
        else minans=max(tmp,minans);
    }
    //printf("%.2lf %.2lf",minans,maxans);
    if(minans>maxans) printf("NO SOLUTION\n");
    else if(minans>0) printf("%d\n",(int)ceil(minans));
    else if(maxans<0) printf("%d\n",(int)floor(maxans));
    else puts("0");
    return 0;
}