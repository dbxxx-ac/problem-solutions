/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 22:37:44 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 22:37:44 
 */
#include <iostream>
using namespace std;
int n,sum,a[10005];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(a[i]>a[j])
                sum++;
    cout<<sum;
    return 0;
}