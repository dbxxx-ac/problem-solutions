/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-04-14 22:11:54 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-04-15 14:54:11
 */
#include <iostream>
#include <cstdio>

const int maxn = 1000005;
const int mod = 10000;
int dp[maxn] = {0, 1, 2, 5};

int main() {
    int n;
    std :: cin >> n;
    if(n <= 3) {
        std :: cout << dp[n] << std :: endl;
        return 0;
    }
    for(int i = 4; i <= n; i++)
        dp[i] = (dp[i - 1] * 2 % mod + dp[i - 3] % mod) % mod;
    std :: cout << dp[n] << std :: endl;
    return 0;
}