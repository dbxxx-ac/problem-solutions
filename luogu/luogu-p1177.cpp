/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 21:31:34 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 21:31:34 
 */
#include <iostream>
#include <algorithm>
using namespace std;
int n,a[1000005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}