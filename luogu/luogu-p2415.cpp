#include <bits/stdc++.h>
using namespace std;
int a[35],i=0;
long long s;
int main(){
    while(cin>>a[i++]);
    for(int j=0;j<i;j++)
        s+=a[j];
    s*=1<<i-2;
    cout<<s;
    return 0;
}