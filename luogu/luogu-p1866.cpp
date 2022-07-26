/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-01 12:35:08 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-01 12:39:40
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

const int mod = 1000000007;
const int maxn = 55;
int a[maxn];

int main() {
    int n;
    long long ans = 1;
    std :: scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        std :: scanf("%d", &a[i]);
    std :: sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i) {
        ans *= (a[i] - i + 1);
        ans %= mod;
    }

    std :: printf("%lld\n", ans);
    return 0;
}