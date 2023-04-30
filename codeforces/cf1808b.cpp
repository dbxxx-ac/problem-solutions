/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-29 17:28:31 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-29 17:35:19
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

const int maxm = (int)3e5 + 5;
std :: vector <int> pts[maxm];

signed main() {
    int T = read();
    while (T--) {
        int n = read(), m = read();
        for (int i = 1; i <= m; ++i) {
            pts[i].clear();
        }
        
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                pts[j].push_back(read());
        
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            std :: sort(pts[i].begin(), pts[i].end());
            for (int j = 0; j < n - 1; ++j)
                ans += (j + 1) * (n - j - 1) * (pts[i][j + 1] - pts[i][j]);
        }

        printf("%lld\n", ans);
    }
    return 0;
}