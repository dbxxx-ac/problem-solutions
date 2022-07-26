/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 21:51:03 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 21:51:03 
 */
#include <iostream>
#include <cstdio>
using namespace std;
int n,m,a[100005];
int l,r;
bool judge(int num)
{
    int sum=0,seg=1;
    for(int i=0;i<n;i++)
    {
        if(sum+a[i]<=num) sum+=a[i];
        else
        {
            seg++;
            //sum=0;
            sum=a[i];
        }
    }
    if(seg>m) return false;
    return true;
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        l=max(l,a[i]);
       // cout<<a[i]<<" ";
        r+=a[i];

    }//cout<<l<<" "<<r<<endl;
    while(l<=r)
    {
        int mid=(l+r)>>1;
     //   cout<<mid<<endl;
        if(judge(mid)) r=mid-1;
        else l=mid+1;
    }
    printf("%d\n",l);
    return 0;
}
