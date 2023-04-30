/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-25 08:46:59 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-25 09:02:00
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
inline bool gmx(int &a, int b) {
    return b > a ? a = b, true : false;
}

const int maxn = (int)1e5 + 5;
int a[maxn], ple[maxn], nle[maxn];

signed main() {
    for (int n = read(); n; n = read()) {
        for (int i = 1; i <= n; ++i)
            a[i] = read();

        std :: stack <int> s;
        for (int i = 1; i <= n; ++i) {
            while (!s.empty() && a[s.top()] > a[i]) {
                nle[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        while (!s.empty()) {
            nle[s.top()] = n + 1;
            s.pop();
        }

        for (int i = n; i; --i) {
            while (!s.empty() && a[s.top()] > a[i]) {
                ple[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        while (!s.empty()) {
            ple[s.top()] = 0;
            s.pop();
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i)
            gmx(ans, a[i] * (nle[i] - 1 - ple[i]));
        printf("%lld\n", ans);
    }
    return 0;
}