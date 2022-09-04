/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-08-27 20:05:39 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-08-27 20:09:25
 */
#include <bits/stdc++.h>

long long n;


int main() {
    scanf("%lld", &n);
    long long x = n % 998244353;

    printf("%lld\n", (x + 998244353) % 998244353);
    return 0;
}