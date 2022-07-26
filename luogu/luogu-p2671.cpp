/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-05 12:58:06 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-05 13:06:43
 */
#include <iostream>
#include <cstdio>

const int maxn = 100005;
const int maxm = 100005;
const int mod = 10007;
typedef long long ll;

ll number[maxn], color[maxn];
ll times[maxm][2], sum[maxm][2];

int main() {
    ll n, m, ans = 0;
    std :: scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; ++i)
        std :: scanf("%lld", &number[i]);
    for (int i = 1; i <= n; ++i)
        std :: scanf("%lld", &color[i]);
    
    for (int i = 1; i <= n; ++i) {
        ++times[color[i]][i % 2];
        sum[color[i]][i % 2] += number[i];
        sum[color[i]][i % 2] %= mod;
    }

    for (int i = 1; i <= n; ++i) {
        ans += (ll)i * ((times[color[i]][i % 2] - 2) * number[i] % mod + sum[color[i]][i % 2]);
        ans %= mod;
    }
    
    std :: printf("%lld\n", ans);
    return 0;
}