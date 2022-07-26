/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-05 14:13:18 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-05 14:26:21
 */
#include <iostream>
#include <cstdio>

const int maxn = 100005;
typedef long long ll;

ll p[maxn];
ll a[maxn], b[maxn], c[maxn];
ll sum[maxn];

ll min(ll a, ll b) {
    return a < b ? a : b;
}

ll max(ll a, ll b) {
    return a > b ? a : b;
}

int main() {
    ll n, m;
    std :: scanf("%lld %lld", &n, &m);
    for (ll i = 1; i <= m; ++i)
        std :: scanf("%lld", &p[i]);
    for (ll i = 1; i <= n - 1; ++i)
        std :: scanf("%lld %lld %lld", &a[i], &b[i], &c[i]);
    
    for (ll i = 2; i <= m; ++i) {
        ll head = min(p[i - 1], p[i]);
        ll tail = max(p[i - 1], p[i]);
        ++sum[head];
        --sum[tail];
    }

    for (ll i = 2; i <= n; ++i)
        sum[i] += sum[i - 1];
    
    ll ans = 0;
    for (ll i = 1; i <= n - 1; ++i)
        ans += min(a[i] * sum[i], b[i] * sum[i] + c[i]);

    std :: printf("%lld\n", ans);
    return 0;
}