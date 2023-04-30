/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-01-02 18:57:20 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-01-02 19:20:56
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
const int maxa = (int)1e5 + 5;
typedef std :: pair <int, int> pii;

int t[maxa];

signed main() {
    int n = read();
    for (int i = 1; i <= n; ++i)
        ++t[read()];
    
    std :: queue <int> q[2];
    for (int i = 1; i <= (int)1e5; ++i)
        while (t[i]--)
            q[0].push(i);
    
    int ans = 0;
    const int inf = LONG_LONG_MAX;

    auto get = [&]() {
        pii p = std :: min(
            std :: make_pair(q[0].empty() ? inf : q[0].front(), 0),
            std :: make_pair(q[1].empty() ? inf : q[1].front(), 1)
        );
        q[p.second].pop();
        return p.first;
    };

    for (int i = 1; i < n; ++i) {
        int x = get(), y = get();
        q[1].push(x + y);
        ans += x + y;
    }

    printf("%lld\n", ans);
    return 0;
}