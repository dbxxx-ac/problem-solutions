/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 21:50:00 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 21:50:00 
 */
//头文件
#include <iostream>
#include <cstdio>
//宏定义

//命名空间
using namespace std;
//变量
int n,ans;
char a[30];
//结构体+typedef

//函数

//主函数
int main()
{
    //取消同步+初始化

    //输入
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    //算法
    for(int i=0;i<n;i++)
    {
            if(i&&a[i]==a[i-1]) continue;//如果不是第一个并且当前值=前一个值，
            //说明这个人和前面那个人穿同一条裤子（逃）同样的衣服，则不进行ans自增（他是等人的
            //ans自增干什么，浪费表情。）
            ans++;//说明当前的不是等人的，则进行ans自增
    }
    //输出
    printf("%d\n",ans+1);//为什么要+1呢？这是Aron前面的人数，小学文化课（逃）老师说过，
    //当前位置=前面人数（在本题中集体数）+1，这个不用多做解释吧
    //结束
    return 0;
}
