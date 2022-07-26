/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-02-26 12:49:17 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-02-26 12:52:15 
 */
#include <iostream>
#include <cstdio>
#include <cmath>

long long gcd(int a,int b) {
    return a % b ? gcd(b,a % b) : b;
}

int main() {
    int m,n;
    int ans = 0;
    scanf("%d%d",&m,&n);

    for(int i = 1; i <= sqrt(m * n);i++)
        if(n * m % i == 0 && gcd(i,n * m / i) == m)
            ans++;
    ans *= 2;
    if(n == m) ans--;
    printf("%d\n",ans);
    return 0;
}