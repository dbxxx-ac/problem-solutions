/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-17 14:17:51 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-17 17:56:41
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

const int maxn = 3.5e4 + 5;
const int maxinf = 0x3f3f3f3f;
const int maxinf2 = 2e5 + 5;
const int mininf2 = -maxinf2;

int a[maxn], p[maxn], l[maxn], f[maxn], g[maxn], h[maxn];

std :: vector <int> v[maxn];

inline int abs(int x) {
    return x > 0 ? x : -x;
}

inline int min(int a, int b) {
    return a < b ? a : b;
}

signed main() {
    int n = read();
    for (int i = 1; i <= n; ++i) {
        a[i] = read() - i;
        f[i] = maxinf;
    }
    
    int len = 1;
    l[1] = 1;
    p[1] = a[1];
    v[1].push_back(1);
    for (int i = 2; i <= n; ++i) {
        if (p[len] <= a[i]) {
            p[++len] = a[i];
            l[i] = len;
            v[len].push_back(i);
        }
        else {
            int x = std :: upper_bound(p + 1, p + 1 + len, a[i]) - p;
            p[x] = a[i];
            l[i] = x;
            v[x].push_back(i);
        }
    }

    v[0].push_back(0);
    a[0] = mininf2;
    a[n + 1] = maxinf2;
    f[n + 1] = maxinf;
    l[n + 1] = len + 1;

    for (int j = 1; j <= n + 1; ++j) {
        for (int t = 0; t < v[l[j] - 1].size(); ++t) {
            int i = v[l[j] - 1][t];
            if (i > j || a[i] > a[j])
                continue;
            g[i] = h[j] = 0;
            for (int k = i + 1; k < j; ++k)
                g[k] = g[k - 1] + abs(a[k] - a[i]);
            for (int k = j - 1; k > i; --k)
                h[k] = h[k + 1] + abs(a[k] - a[j]);
            
            int val = maxinf;
            for (int k = i; k < j; ++k)
                val = min(val, g[k] + h[k + 1]);
            f[j] = min(f[j], f[i] + val);
        }
    }
    printf("%lld\n%lld\n", n - len, f[n + 1]);
    return 0;
}

// 4 0 0 1