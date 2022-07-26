/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-06 09:22:22 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-06 09:36:07
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

const long long maxn = 1005;
const long long maxm = 1005;

char a[maxn][maxm];
int maxdraw[maxm], dp[maxm];

std :: stack <long long> s;

int main() {
    long long n, m;
    std :: scanf("%lld %lld", &n, &m);
    for (long long i = 1; i <= n; ++i)
        std :: scanf("%s", a[i] + 1);
    
    long long ans = n * m * (n + 1) * (m + 1) / 4;
    for (long long i = 1; i <= n; ++i) {
        while (!s.empty())
            s.pop();
        std :: memset(dp, 0, sizeof(dp));
        
        for (long long j = 1; j <= m; ++j) {
            if (a[i][j] == '*')
                maxdraw[j] = i;
            while (!s.empty() && maxdraw[s.top()] <= maxdraw[j])
                s.pop();
            int k = s.empty() ? 0 : s.top();
            dp[j] = dp[k] + maxdraw[j] * (j - k);
            ans -= dp[j];
            s.push(j);
        }
    }

    std :: printf("%lld\n", ans);
    return 0;
}