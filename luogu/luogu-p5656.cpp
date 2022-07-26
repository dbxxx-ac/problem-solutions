/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-18 09:38:48 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-18 12:26:50
 */
#include <bits/stdc++.h>
#define int long long

inline int read() {
    int x = 0;
    bool flag = true;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-')
            flag = false;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if(flag)
        return x;
    return ~(x - 1);
}

int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

signed main() {
    int T = read();
    while (T--) {
        int a = read(), b = read(), c = read(), x = 0, y = 0;
        int d = exgcd(a, b, x, y), p = b / d, q = a / d;
        if (c % d != 0) {
            puts("-1");
            continue;
        }
        x *= c / d;
        y *= c / d;
        // x +- p * Z, y +- p * Z
        // x - p * Z >= 1
        // x >= 1 + p * Z
        // p * Z <= x - 1
        int z = (x - 1) / p;
        if (x < 0)
            z = -((p - x) / p);
        // -
        x -= p * z;
        y += q * z;
        if (y > 0) {
            printf("%lld ", (y - 1) / q + 1);
            printf("%lld ", x);
            printf("%lld ", (y - 1) % q + 1);
            printf("%lld ", x + (y - 1) / q * p);
            printf("%lld\n", y);
        } else {
            // y + q * Z >= 1
            // q * Z >= 1 - y
            // Z >= ceil((1 - y) / q)
            // ceil((1 - y) / q) = (q - y) / q
            printf("%lld ", x);
            printf("%lld\n", y + (q - y) / q * q);
        }

        /*
        4 / 4 = 1 1
        5 / 4 = 1 2
        6 / 4 = 1 2
        7 / 4 = 1 2
        8 / 4 = 2 2
        9 / 4 = 2 3

        */
    }
    return 0;
}