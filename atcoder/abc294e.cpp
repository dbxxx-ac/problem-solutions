/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-19 20:50:16 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-19 20:58:47
 */
#include <bits/stdc++.h>
#define int long long 
inline int read() {
    int x = 0;
    bool f = true;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            f = false;
    for (; isdigit(ch); ch = getchar())
        x = (x << 1) + (x << 3) + ch - '0';
    return f ? x : (~(x - 1));
}

typedef std :: pair <int, int> pii;
std :: vector <pii> v1, v2;

signed main() {
    int _ = read(), n1 = read(), n2 = read();
    for (int i = 1; i <= n1; ++i) {
        int a = read(), b = read();
        v1.push_back({a, b});
    }
    for (int i = 1; i <= n2; ++i) {
        int a = read(), b = read();
        v2.push_back({a, b});
    }

    int ans = 0;
    for (int i = 0, j = 0; i < n1 && j < n2; ) {
        int a = v1[i].first, b = v1[i].second;
        int c = v2[j].first, d = v2[j].second;
        // printf("%lld %lld %lld %lld %lld %lld\n", i, j, a, b, c, d);
        int times = (a == c ? 1 : 0);
        if (b < d) {
            ans += times * b;
            ++i;
            v2[j].second -= b;
        } else if (b > d) {
            ans += times * d;
            ++j;
            v1[i].second -= d;
        } else {
            ans += times * b;
            ++i;
            ++j;
        }
    }

    printf("%lld\n", ans);
    return 0;
}