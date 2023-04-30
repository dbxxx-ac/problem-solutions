/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-20 15:40:23 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-20 16:19:27
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
inline int lowbit(int x) {
    return x & (-x);
}
const int maxn = (int)1e5 + 5;

int a[maxn], au[maxn];
std :: vector <int> G[maxn];

int c[maxn];

int n;
inline void add(int x) {
    for (; x <= n; x += lowbit(x))
        ++c[x];
    return ;
}

inline int get(int x) {
    int sum = 0;
    for (; x; x -= lowbit(x))
        sum += c[x];
    return sum;
}

int ans[maxn];
void dfs(int u) {
    ans[u] = -get(a[u]);
    for (int v : G[u])
        dfs(v);
    ans[u] += get(a[u]);
    // 这里有个细节，为什么可以直接 get(a[u]) 呢；
    // 这难道不是直接获取权值小于等于 a[u] 的点的吗？
    // 的确，我们的需求是小于；
    // 但是本题中保证权值互异；
    // 权值等于 a[u] 的点只有 u 自己；
    // 因此只需要考虑 u 的影响，那在查询完之后再标记 a[u] 即可。

    // 当然可以不想这么多。。直接 get(a[u] - 1) 即可。
    add(a[u]);
}

signed main() {
    n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    for (int i = 2; i <= n; ++i) {
        int x = read();
        G[x].push_back(i);
    }

    std :: copy(a + 1, a + 1 + n, au + 1);
    std :: sort(au + 1, au + 1 + n);
    auto en = std :: unique(au + 1, au + 1 + n);
    
    for (int i = 1; i <= n; ++i)
        a[i] = n + 1 - (std :: lower_bound(au + 1, en, a[i]) - au);
    
    dfs(1);

    for (int u = 1; u <= n; ++u)
        printf("%lld\n", ans[u]);
    
    return 0;
}