/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-01-04 14:14:32 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-01-04 14:20:19
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
inline char rech() {
    char ch = getchar();
    while (!isgraph(ch))
        ch = getchar();
    return ch;
}

const int maxn = 150005;
const int sqtn = 405;
int a[maxn], ans[sqtn][sqtn];

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    int t = (int)sqrt(n);

    for (int p = 1; p <= t; ++p)
        for (int i = 1; i <= n; ++i)
            ans[p][i % p] += a[i];
    
    while (m--) {
        char op = rech();
        if (op == 'A') {
            int p = read(), q = read();
            if (p <= t)
                printf("%d\n", ans[p][q]);
            else {
                int now = 0;
                for (int i = q; i <= n; i += p)
                    now += a[i];
                printf("%d\n", now);
            }
        } else {
            int x = read(), v = read();
            for (int p = 1; p <= t; ++p)
                ans[p][x % p] += v - a[x];
            a[x] = v;
        }
    }
    return 0;
}