/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-03 22:52:17 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-03 23:34:45
 */
#include <iostream>
#include <cstdio>

const int maxn = 1000005;
const int mod = 666623333;
typedef long long ll;

bool isprime[maxn];
ll prime_num[maxn], cnt;
ll phi[maxn], last[maxn];

void prime(ll n) {
    for (ll i = 2; i <= n; ++i)
        isprime[i] = true;
    isprime[1] = false;
    for (ll i = 2; i <= n; ++i) {
        if (isprime[i]) prime_num[++cnt] = i;
        for (ll j = 1; j <= cnt && i * prime_num[j] <= n; ++j) {
            isprime[i * prime_num[j]] = false;
            if (i % prime_num[j] == 0) break;
        }
    }
}

int main() {
    ll l, r;
    std :: scanf("%lld %lld", &l, &r);
    prime(maxn - 5);
    for (ll i = l; i <= r; ++i) {
        ll idx = i - l;
        phi[idx] = last[idx] = i;
    }

    for (ll i = 1; i <= cnt && prime_num[i] * prime_num[i] <= r; ++i) {
        ll p = prime_num[i];
        for (ll j = l / p * p + ((l % p) ? p : 0); j <= r; j += p) {
            ll idx = j - l;
            phi[idx] /= p;
            phi[idx] *= p - 1;
            while (last[idx] % p == 0)
                last[idx] /= p;
        }
    }
    
    for (ll i = l; i <= r; ++i) {
        ll idx = i - l;
        if (last[idx] > 1) {
            phi[idx] /= last[idx];
            phi[idx] *= (last[idx] - 1);
        }
    }

    ll ans = 0;
    for (ll i = l; i <= r; ++i) {
        ll idx = i - l;
        ans = (ans + (i - phi[idx]) % mod) % mod;
    }

    std :: printf("%lld\n", ans);
    return 0;
}