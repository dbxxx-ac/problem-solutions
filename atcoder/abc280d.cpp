/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-12-03 20:32:23 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-12-03 20:42:46
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

std :: vector <pii> fac;

bool check(int x) {
    for (auto [p, q] : fac) {
        int cnt = 0;
        for (int r = p; r <= x; r *= p)
            cnt += x / r;
        if (cnt < q)
            return false;
    }
    return true;
}

signed main() {
    int k = read();
    
    int tmp = k;
    for (int i = 2; i * i <= k; ++i) {
        int cnt = 0;
        while (tmp % i == 0) {
            ++cnt;
            tmp /= i;
        }
        if (cnt)
            fac.emplace_back(i, cnt);
    }
    if (tmp != 1) {
        printf("%lld\n", tmp);
        return 0;
    }

    int ans = 1;
    for (int i = (1 << 25); i; i >>= 1) {
        if (!check(ans + i))
            ans += i;
    }
    printf("%lld\n", ans + 1);

    return 0;
}