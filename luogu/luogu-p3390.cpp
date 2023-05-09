/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-05-08 20:35:25 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-05-08 20:53:41
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

const int N = 105;
const int mod = (int)1e9 + 7;

struct phalanx {
    int a[N][N];
    int n;

    phalanx(int _n) : n(_n) {}

    const void operator = (const std :: vector <int> v) {
        assert(v.size() == n * n);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                a[i][j] = v[(i - 1) * n + j - 1];
    }

    const void operator = (const int x) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                a[i][j] = ((i == j) ? x : 0);
    }

    const phalanx operator * (const phalanx b) const {
        assert(b.n == n);
        phalanx ans(n);
        ans = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                for (int k = 1; k <= n; ++k)
                    (ans.a[i][j] += a[i][k] * b.a[k][j] % mod) %= mod;
        return ans;
    }

    const void operator *= (const phalanx b) {
        *this = (*this * b);
    }

    inline phalanx power(int T) {
        phalanx ans(n), a = *this;
        ans = 1;
        for (; T; T >>= 1, a *= a)
            if (T & 1)
                ans *= a;
        return ans;
    }
};

signed main() {
    int n = read(), k = read();
    phalanx a(n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            a.a[i][j] = read();
    a = a.power(k);
    for (int i = 1; i <= n; ++i, puts(""))
        for (int j = 1; j <= n; ++j)
            printf("%lld ", a.a[i][j]);
    return 0;
}