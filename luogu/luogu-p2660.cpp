/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-03 22:00:29 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-03 22:05:41
 */
#include <iostream>
#include <cstdio>

typedef long long ll;
void swap(ll &x, ll &y) {
    x ^= y;
    y ^= x;
    x ^= y;
}

int main() {
    ll x, y, ans = 0;
    std :: scanf("%lld %lld", &x, &y);
    while (x && y) {
        swap(x, y);
        ans += (y << 2) * (x / y);
        x %= y;
    }
    std :: printf("%lld\n", ans);
    return 0;
}