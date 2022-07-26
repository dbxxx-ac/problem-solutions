/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-02-24 16:52:07 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-02-24 16:53:12 
 */
#include <iostream>
#include <cstdio>

int n;
long long ans;

int main() {
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) ans += n / i;
    printf("%lld\n",ans);
    return 0;
}