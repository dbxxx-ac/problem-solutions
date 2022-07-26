/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-03-03 21:36:03 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-03-03 21:43:47
 */
#include <iostream>
#include <cstdio>

const int maxn = 35;
int dp[maxn][maxn];

int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    dp[0][1] = 1;
    for(int i = 1; i <= m; i++) {
        dp[i][1] = dp[i - 1][n] + dp[i - 1][2];
        dp[i][n] = dp[i - 1][n - 1] + dp[i - 1][1];

        for(int j = 2; j <= n - 1; j++)
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];

    }
    printf("%d\n",dp[m][1]);
    return 0;    
}