/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-06 08:55:20 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-06 09:04:16
 */
#include <iostream>
#include <cstdio>

const int maxn = 1000005;

long long a[maxn];
long long sum[maxn];

int main() {
    int n, k;
    std :: scanf("%d %d", &n, &k);
    for (int i = 1; i <= n - 1; ++i)
        std :: scanf("%lld", &a[i]);
    
    for (int i = 1; i <= n - 1; ++i)
        sum[i] = sum[i - 1] + a[i];
    
    long long maxt = sum[k];
    for (int i = k + 1; i <= n - 1; ++i) {
        long long t = sum[i] - sum[i - k];
        maxt = t > maxt ? t : maxt;
    }

    std :: printf("%lld", sum[n - 1] - maxt);
    return 0;
}