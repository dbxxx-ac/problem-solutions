/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-20 11:16:31 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-20 11:19:29
 */
#include <iostream>
#include <cstdio>

typedef long long ll;

int main() {
    int T;
    std :: scanf("%d", &T);
    while (T--) {
        ll n;
        std :: scanf("%lld", &n);
        if (n % 2 != 0)
            std :: printf("%lld\n", n * (n - 1) / 2);
        else
            std :: printf("%lld\n", (n * (n - 1) - n + 2) / 2);
    }
    return 0;
}