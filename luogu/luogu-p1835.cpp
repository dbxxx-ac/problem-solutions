/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-02 18:22:14 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-02 19:40:04
 */
#include <iostream>
#include <cstdio>

const int maxn = 50005;
const int maxd = 1000005;

int prime_num[maxn], cnt;
bool isprime[maxn];
bool isprime2[maxd];

void prime(int n) {
    for (int i = 1; i <= n; ++i)
        isprime[i] = true;
    isprime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (isprime[i]) prime_num[++cnt] = i;
        for (int j = 1; j <= cnt && prime_num[j] * i <= n; ++j) {
            isprime[prime_num[j] * i] = false;
            if (i % prime_num[j] == 0) break;
        }
    }
}

int main() {
    long long l, r, ans = 0;
    std :: scanf("%lld %lld", &l, &r);
    prime(50000);
    if (l == 1) l = 2;
    for (int i = 1; i <= cnt; ++i) {
        int x = prime_num[i];
        for (long long j = (l + x - 1) / x * x > x * 2 ? (l + x - 1) / x * x : x * 2; j <= r; j += x)
            isprime2[j - l + 1] = true;
    }

    for (int i = 1; i <= r - l + 1; ++i)
        if (!isprime2[i])
            ++ans;
    
    std :: printf("%lld\n", ans);
    return 0;
}