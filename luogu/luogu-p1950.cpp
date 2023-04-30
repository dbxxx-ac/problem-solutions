/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-25 17:53:24 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-25 18:04:25
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
inline char rech() {
    char ch = getchar();
    while (!isgraph(ch))
        ch = getchar();
    return ch;
}

const int maxm = 1005;

int h[maxm], ple[maxm], nnge[maxm];

signed main() {
    int ans = 0, n = read(), m = read();
    while (n--) {
        for (int i = 1; i <= m; ++i)
            h[i] = (rech() == '.') ? (h[i] + 1) : 0;
        std :: stack <int> s;
        for (int i = 1; i <= m; ++i) {
            while (!s.empty() && h[i] <= h[s.top()]) {
                nnge[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) {
            nnge[s.top()] = m + 1;
            s.pop();
        }
        for (int i = m; i; --i) {
            while (!s.empty() && h[i] < h[s.top()]) {
                ple[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) {
            ple[s.top()] = 0;
            s.pop();
        }
        
        for (int i = 1; i <= m; ++i)
            ans += h[i] * (i - ple[i]) * (nnge[i] - i);
    }
    printf("%lld\n", ans);
    return 0;
}