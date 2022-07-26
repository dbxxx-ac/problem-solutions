/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-04-12 20:54:32 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-04-12 21:06:47
 */
#include <iostream>
#include <cstdio>
#include <cstring>

inline int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int s[5], ans = 0;
    for(int i = 1; i <= 4; i++) std :: cin >> s[i];
    for(int i = 1; i <= 4; i++) {
        int sum = 0, a[25], dp[1205] = {0};
        for(int j = 1; j <= s[i]; j++) {
            std :: cin >> a[j];
            sum += a[j];
        }
        for(int j = 1; j <= s[i]; j++)
            for(int k = sum / 2; k >= a[j]; k--)
                dp[k] = max(dp[k], dp[k - a[j]] + a[j]);
        ans += sum - dp[sum / 2];
    }
    std :: cout << ans << std :: endl;
    return 0;
}