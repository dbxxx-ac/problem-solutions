/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-05 14:43:16 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-05 14:54:39
 */
#include <iostream>
#include <cstdio>
#include <cstring>

const int infmin = -1008610086;
const int maxn = 125;

int a[maxn][maxn];
int sum[maxn], dp[maxn];
int ans = infmin;

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    std :: scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            std :: scanf("%d", &a[i][j]);
    
    for (int i = 1; i <= n; ++i) {
        std :: memset(sum, 0, sizeof(sum));
        for (int j = i; j <= n; ++j) {
            for (int k = 1; k <= n; ++k)
                sum[k] += a[j][k];
            std :: memset(dp, 0, sizeof(dp));
            for (int l = 1; l <= n; ++l)
                dp[l] = max(dp[l], dp[l - 1] + sum[l]);
            for (int l = 1; l <= n; ++l)
                ans = max(ans, dp[l]);
        }
    }

    std :: printf("%d\n", ans);
    return 0;
}