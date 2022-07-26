/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-02-28 16:18:47 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-03-01 23:28:48
 */
#include <iostream>
#include <cstdio>

int n,k;
int dp[100005];
const int mod = 100003;

int main() {
    scanf("%d%d",&n,&k);
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= k; i++)
        dp[i] = dp[i - 1] * 2 % mod;
    for(int i = k + 1; i <= n; i++)
        dp[i] = (dp[i - 1] * 2 - dp[i - k - 1])% mod;
    printf("%d\n",(dp[n] + mod) % mod);
    return 0;
}