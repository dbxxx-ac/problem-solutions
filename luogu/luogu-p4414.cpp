/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 22:38:07 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 22:38:07 
 */
#include <bits/stdc++.h>
using namespace std;
int a[3];
char A,B,C;
int main()
{
    cin>>a[0]>>a[1]>>a[2];
    cin>>A>>B>>C;
    sort(a,a+3);
    cout<<a[A-65]<<" "<<a[B-65]<<" "<<a[C-65];
    return 0;
}