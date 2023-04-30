/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-12 22:57:06 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-12 23:11:43
 */
#include <bits/stdc++.h>
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

const int maxn = (int)2e5 + 5;

int a[maxn];

int main() {
    int T = read();
    while (T--) {
        int n = read(), k = read(), d = read(), w = read();
        for (int i = 1; i <= n; ++i)
            a[i] = read();
        int ans = 0;
        for (int now = 1; now <= n; ) {
            ++ans;
            int lst = now;
            for (; ;) {
                ++lst;
                if (lst > n)
                    break;
                if (lst - now >= k)
                    break;
                if (a[lst] > a[now] + w + d)
                    break;
            }
            // printf("%d ", lst);
            now = lst;
        }
        printf("%d\n", ans);
    }
    return 0;
}