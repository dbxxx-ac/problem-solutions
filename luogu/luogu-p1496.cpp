/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-31 10:05:40 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-31 10:48:49
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

const int maxn = 20005;

long long b[maxn], e[maxn];

int main() {
    int n;
    std :: scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        std :: scanf("%lld %lld", &b[i], &e[i]);

    std :: sort(b + 1, b + 1 + n);
    std :: sort(e + 1, e + 1 + n);

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += e[i] - b[i];
        if (i < n && e[i] > b[i + 1])
            ans -= e[i] - b[i + 1];
    }

    std :: printf("%lld\n", ans);
    return 0;
}