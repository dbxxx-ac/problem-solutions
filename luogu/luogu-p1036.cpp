#include <iostream>
#include <cstdio>
using namespace std;

bool isprime(int a){//判断素数
    /*0和1特判真的没啥用对这题
    吐槽：题中n的数据范围很奇怪，
    n还有可能=1.....那k<n......
    */
    for(int i=2;i*i<=a;i++)//不想用sqrt，还要头文件
        if(a%i==0)//如果整除
            return false;//扔回false
    //程序都到这里的话就说明此为素数
    //否则就被扔回了
    return true;//扔回true
}

int n,k;
int a[25];
long long ans;

void dfs(int m,int sum,int startx){//最重要的递归
//m代表现在select了多少个数
//sum表示当前的和
//startx表示升序排列，以免算重
    if(m==k){//如果选完了的话
        if(isprime(sum))//如果和是素数
            ans++;//ans加一
        return ;
    }
    for(int i=startx;i<n;i++)
        dfs(m+1,sum+a[i],i+1);//递归
        //步数要加一，和也要加
        //升序起始值要变成i+1,以免算重
    return ;//这一个步骤下，所有的都枚举完了
    //直接返回去
}

int main(){
    scanf("%d%d",&n,&k);//输入
    
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);//循环读入
    dfs(0,0,0);//调用函数
    printf("%d\n",ans);//输出答案
    return 0;//结束程序
}
//本蒟蒻的第一篇题解，求过