/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-09-04 08:57:38 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-09-04 10:17:52
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

const int maxn = (int)1e5 + 5;
const int maxm = (int)1e5 + 5;
const int maxq = (int)1e5 + 5;
const int mod = 998244353;

int a[maxn];

int t[maxm], p[maxm], v[maxm], mul[maxm], cnt[maxm];

std :: vector <int> G[maxn], R[maxn];
int ind[maxn], oud[maxn];

int n, m;

inline void getmul() {
    std :: queue <int> q;
    for (int i = 0; i <= m; ++i) {
        if (oud[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : R[u]) {
            (mul[v] *= mul[u]) %= mod;
            --oud[v];
            if (oud[v] == 0)
                q.push(v);
        }
    }
    return ;
}

inline void getcnt() {
    std :: queue <int> q;
    for (int i = 0; i <= m; ++i)
        if (ind[i] == 0)
            q.push(i);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int cur = 1;
        for (auto v : G[u]) {
            (cnt[v] += cnt[u] * cur) %= mod;
            (cur *= mul[v]) %= mod;
            --ind[v];
            if (ind[v] == 0)
                q.push(v);
        }
    }
}

signed main() {
    n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    
    m = read();
    for (int i = 1; i <= m; ++i) {
        int tp = read();
        t[i] = tp;
        if (tp == 1) {
            p[i] = read();
            v[i] = read();
            mul[i] = 1;
        } else if (tp == 2) {
            mul[i] = read();
        } else if (tp == 3) {
            for (int _ = read(); _ >= 1; --_) {
                int x = read();
                G[i].push_back(x);
                R[x].push_back(i);
                ++ind[x];
                ++oud[i];
            }
            std :: reverse(G[i].begin(), G[i].end());
            mul[i] = 1;
        }
    }

    cnt[0] = mul[0] = 1;
    for (int _ = read(); _ >= 1; --_) {
        int x = read();
        G[0].push_back(x);
        R[x].push_back(0);
        ++ind[x];
        ++oud[0];
    }
    std :: reverse(G[0].begin(), G[0].end());

    getmul();
    getcnt();

    for (int i = 1; i <= n; ++i)
        (a[i] *= mul[0]) %= mod;
    
    for (int i = 1; i <= m; ++i) if (t[i] == 1)
        (a[p[i]] += v[i] * cnt[i] % mod) %= mod;

    for (int i = 1; i <= n; ++i)
        printf("%lld ", a[i]);
    
    return 0;
}