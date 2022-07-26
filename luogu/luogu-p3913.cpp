/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-01 16:46:44 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-01 17:18:07
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

const int maxk = 1000005;

long long n, k;
int r[maxk], c[maxk];

int main() {
    std :: scanf("%lld %lld", &n, &k);
    for (int i = 1; i <= k; ++i)
        std :: scanf("%d %d", &r[i], &c[i]);
    std :: sort(r + 1, r + k + 1);
    std :: sort(c + 1, c + k + 1);
    long long sizex = std :: unique(r + 1, r + k + 1) - r - 1;
    long long sizey = std :: unique(c + 1, c + k + 1) - c - 1;
    std :: printf("%lld\n", n * n - (n - sizex) * (n - sizey));
    return 0;
}