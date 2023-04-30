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

const int mod = (int)1e9 + 7;
const int maxn = 300005;

int a[maxn], b[maxn];

inline int C3(int x) {
    return x * (x - 1) / 2 * (x - 2) / 3;
}

inline int C2(int x) {
    return x * (x - 1) / 2;
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

typedef std :: pair <int, int> pii;
std :: map <pii, int> m;

signed main() {
    int n = read();
    for (int i = 1; i <= n; ++i) {
        int a = read(), b = read();
        read();
        
        if (a == 0)
            b = 1;
        else if (b == 0)
            a = 1;
        else {
            int d = gcd(a, b);
            a /= d;
            b /= d;
        }

        ++m[std :: make_pair(a, b)];
    }

    int ans = C3(n) % mod;
    for (auto it : m) {
        int cnt = it.second;
        if (cnt >= 2)
            ans -= C2(cnt) * (n - cnt) % mod;
        if (cnt >= 3)
            ans -= C3(cnt) % mod;
        (ans += mod) %= mod;
    }

    printf("%lld\n", ans);
    return 0;
}