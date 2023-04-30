/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-25 10:17:19 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-25 18:00:46
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
inline char rech() {
    char ch = getchar();
    while (!isalpha(ch))
        ch = getchar();
    return ch;
}

inline int lowbit(int x) {
    return x & (-x);
}

const int maxn = (int)1e6 + 5;
const int maxm = (int)1e6 + 5;

int typ[maxm], op1[maxm], op2[maxm];

int ua[maxn];

struct fenwick {
    int c[maxn], n;

    inline void add(int x, int v) {
        for (; x <= n; x += lowbit(x))
            c[x] += v;
    }

    inline int get(int x) {
        int ans = 0;
        for (; x; x -= lowbit(x))
            ans += c[x];
        return ans;
    }
} t1, t2;

int a[maxn];

int *en;

inline int lsh(int x) {
    return std :: lower_bound(ua + 1, en, x) - ua;
}

signed main() {
    int n = read(), m = read();

    ua[1] = 0;
    for (int i = 1; i <= m; ++i) {
        char ch = rech();
        typ[i] = (ch == 'U' ? 1 : 2);
        op1[i] = read();
        op2[i] = read();
        ua[i + 1] = op2[i];
    }

    std :: sort(ua + 1, ua + m + 2);
    en = std :: unique(ua + 1, ua + m + 2);

    t1.n = t2.n = m + 1;
    t1.add(lsh(0), n);
    for (int i = 1; i <= m; ++i) {
        if (typ[i] == 1) {
            int x = op1[i], v = op2[i];
            int lax = lsh(a[x]), lv = lsh(v);
            t1.add(lax, -1);
            t2.add(lax, -a[x]);
            a[x] = v;
            t1.add(lv, 1);
            t2.add(lv, v);
        } else {
            int c = op1[i], s = op2[i], ls = lsh(s);
            int f = t1.get(ls), g = t2.get(ls);
            puts(f * s - g <= s * (n - c) ? "TAK" : "NIE");
        }
    }

    return 0;
}