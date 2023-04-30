/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-20 11:39:30 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-20 12:35:49
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
inline bool gmx(int &a, int b) {
    return b > a ? a = b, true : false;
}

const int maxs = 105;
const int maxn = 105;
const int maxm = 20005;

int f[maxm];
std :: vector <int> a[maxn];

int main() {
    int s = read(), n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        a[i].push_back(0);
    
    for (int i = 1; i <= s; ++i)
        for (int j = 1; j <= n; ++j)
            a[j].push_back(read());

    for (int i = 1; i <= n; ++i)
        std :: sort(a[i].begin(), a[i].end());
    
    for (int i = 1; i <= n; ++i)
        for (int v = m; ~v; --v)
            for (int k = 1; k <= s && 2 * a[i][k] + 1 <= v; ++k)
                gmx(f[v], f[v - 2 * a[i][k] - 1] + i * k);
    
    printf("%d\n", f[m]);
    return 0;
}
