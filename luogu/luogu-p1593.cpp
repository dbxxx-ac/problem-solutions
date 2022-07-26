/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-05 00:06:59 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-05 00:22:41
 */
#include <iostream>
#include <cstdio>

typedef long long ll;

const ll mod = 9901;

ll quick_pow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ll a, b, ans = 1;
    std :: scanf("%lld %lld", &a, &b);
    ll div = a;

    for (ll i = 2; i * i <= a; ++i) {
        if (div % i == 0) {
            ll t;
            for (t = 0; div % i == 0; ++t)
                div /= i;
            if (i % mod == 1) {
                ans *= t;
                ans %= mod;
            } else {
                ll p = i % mod;
                ll q = t * b + 1;
                ans *= (quick_pow(p, q) - 1) * quick_pow(p - 1, mod - 2);
                ans %= mod;
            }
        }
    }

    if (div != 1) {
        if (div % mod == 1) {
            ans *= b + 1;
            ans %= mod;
        } else {
            ll p = div % mod;
            ll q = b + 1;
            ans *= (quick_pow(p, q) - 1) * quick_pow(p - 1, mod - 2);
            ans %= mod;
        }
    }

    std :: printf("%lld\n", ans);
    return 0;
}