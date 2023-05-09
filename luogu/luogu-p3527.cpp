/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-05-02 19:55:21 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-05-02 20:50:37
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

const int N = (int)3e5 + 5;
const int M = (int)3e5 + 5;
const int Q = (int)3e5 + 5;

struct fenwick {
    inline int lowbit(int x) {
        return x & (-x);
    }
    int t[M];
    inline void add(int x, int v) {
        for (; x < M; x += lowbit(x))
            t[x] += v;
    }
    inline void rain(int l, int r, int v) {
        if (l <= r) {
            add(l, v);
            add(r + 1, -v);
        } else {
            add(1, v);
            add(r + 1, -v);
            add(l, v);
        }
    }
    inline int query(int x) {
        int ans = 0;
        for (; x; x -= lowbit(x))
            ans += t[x];
        return ans;
    }
} fw;

struct shower {
    int id, l, r, x;
} qry[Q];

std :: vector <int> loc[N];
int ans[N], p[N];

void solve(std :: vector <int> qls, int l, int r) {
    if (qls.empty())
        return ;
    if (l == r) {
        for (int i : qls)
            ans[i] = l;
        return ;
    }

    int mid = (l + r) >> 1;
    for (int i = l; i <= mid; ++i)
        fw.rain(qry[i].l, qry[i].r, qry[i].x);
    
    std :: vector <int> lq, rq;

    for (int i : qls) {
        int ans = 0;
        for (int j : loc[i]) {
            ans += fw.query(j);
            if (ans >= p[i])
                break;
        }
        if (ans >= p[i])
            lq.push_back(i);
        else {
            rq.push_back(i);
            p[i] -= ans;
        }
    }

    for (int i = l; i <= mid; ++i)
        fw.rain(qry[i].l, qry[i].r, -qry[i].x);
    
    solve(lq, l, mid);
    solve(rq, mid + 1, r);
    return ;
}

signed main() {
    int n = read(), m = read();
    for (int i = 1; i <= m; ++i)
        loc[read()].push_back(i);
    for (int i = 1; i <= n; ++i)
        p[i] = read();
    int q = read();
    for (int i = 1; i <= q; ++i) {
        int l = read(), r = read(), x = read();
        qry[i] = (shower){i, l, r, x};
    }
    
    std :: vector <int> qls;
    for (int i = 1; i <= n; ++i)
        qls.push_back(i);
    solve(qls, 1, q + 1);

    for (int i = 1; i <= n; ++i) {
        if (ans[i] == q + 1)
            puts("NIE");
        else
            printf("%lld\n", ans[i]);
    }
    return 0;
}