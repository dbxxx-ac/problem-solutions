/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-30 20:08:14 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-30 20:27:31
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

const int maxk = (int)1e5 + 5;
const int maxn = (int)1e5 + 5;
typedef std :: pair <int, int> pii;

int a[maxk], tp[maxn];
pii asi[maxk];

struct node {
    int id, x, p, q;
    bool operator < (node b) {
        return p * b.q > b.p * q;
    }
};

signed main() {
    int k = read(), n = read(), m = read();
    std :: vector <node> add, mul;
    for (int i = 1; i <= k; ++i)
        a[i] = read();
    for (int i = 1; i <= n; ++i) {
        int t = read(), x = read(), v = read();
        tp[i] = t;
        if (t == 1)
            asi[x] = std :: max(asi[x], std :: make_pair(v, i));
        else if (t == 2)
            add.push_back({i, x, v, 1});
        else
            mul.push_back({i, x, v - 1, 1});
    }

    for (int i = 1; i <= k; ++i)
        if (asi[i].first > a[i])
            add.push_back({asi[i].second, i, asi[i].first - a[i], 1});
    
    std :: sort(add.begin(), add.end());
    for (node o : add) {
        int id = o.id, x = o.x, p = o.p;
        mul.push_back({id, x, p, a[x]});
        a[x] += p;
    }
    
    std :: sort(mul.begin(), mul.end());
    m = std :: min(m, (int)mul.size()); 
    std :: sort(mul.begin(), mul.begin() + m, [](node a, node b) {
        return tp[a.id] < tp[b.id];
    });

    printf("%lld\n", m);
    for (int i = 0; i < m; ++i)
        printf("%lld ", mul[i].id);
    puts("");
    return 0;
}