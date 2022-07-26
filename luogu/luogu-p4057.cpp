/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-03 20:09:50 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-03 20:12:55
 */
#include <iostream>
#include <cstdio>

typedef long long ll;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    ll a, b, c;
    std :: scanf("%lld %lld %lld", &a, &b, &c);
    std :: printf("%lld\n", lcm(lcm(a, b), c));
    return 0;
}