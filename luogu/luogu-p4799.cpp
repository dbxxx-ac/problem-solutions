/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-12-20 23:35:43 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-01 19:51:05
 */
#include <bits/stdc++.h>
typedef unsigned long long ull;

inline ull read() {
    ull x = 0;
    bool f = true;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = false;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if (f)
        return x;
    return ~(x - 1);
}

int n;
ull m;
const int maxn = 45;
ull a[maxn];
std :: vector <ull> v1, v2;

void dfs(int l, int r, ull cur, std :: vector <ull>& v) {
    if (cur > m)
        return ;
    if (l > r) {
        v.push_back(cur);
        return ;
    }
    dfs(l + 1, r, cur, v);
    dfs(l + 1, r, cur + a[l], v);
}

int main() {
    n = read();
    m = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    dfs(1, n >> 1, 0, v1);
    dfs((n >> 1) + 1, n, 0, v2);

    std :: sort(v1.begin(), v1.end());
    ull ans = 0;
    for (int i = 0; i < v2.size(); ++i)
        ans += std :: upper_bound(v1.begin(), v1.end(), m - v2[i]) - v1.begin();
    std :: printf("%llu\n", ans);
    return 0;
}