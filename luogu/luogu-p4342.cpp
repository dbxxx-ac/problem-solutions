/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-11-12 13:03:15 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-11-12 13:29:00
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
    while (!isalpha(ch))
        ch = getchar();
    return ch;
}
inline bool gmx(int &a, int b) {
    return b > a ? a = b, true : false;
}
inline bool gmi(int &a, int b) {
    return b < a ? a = b, true : false;
}

const int maxn2 = 105;

char opt[maxn2];
int f[maxn2][maxn2], g[maxn2][maxn2];

int main() {
    int n = read(), n2 = n << 1;
    
    std :: memset(f, 0xc0, sizeof(f));
    std :: memset(g, 0x3f, sizeof(g));
    
    for (int i = 1; i <= n; ++i) {
        opt[i] = opt[i + n] = rech();
        f[i][i] = f[i + n][i + n] = g[i][i] = g[i + n][i + n] = read();
    }

    for (int len = 2; len <= n; ++len) {
        for (int l = 1, r = len; r <= n2; ++l, ++r) {
            for (int i = l; i < r; ++i) {
                char op = opt[i + 1];
                int lmx = f[l][i], rmx = f[i + 1][r];
                int lmi = g[l][i], rmi = g[i + 1][r];

                if (op == 't') {
                    gmx(f[l][r], lmx + rmx);
                    gmi(g[l][r], lmi + rmi);
                } else {
                    std :: pair <int, int> p;
                    p = std :: minmax({lmi * rmi, lmi * rmx, lmx * rmi, lmx * rmx});
                    gmx(f[l][r], p.second);
                    gmi(g[l][r], p.first);
                }
            }
        }
    }

    int ans = -INT_MAX;
    std :: vector <int> vt;
    
    for (int l = 1, r = n; l <= n; ++l, ++r) {
        if (f[l][r] >= ans) {
            if (f[l][r] > ans)
                vt.clear();
            vt.push_back(l);
            ans = f[l][r];
        }
    }
    
    printf("%d\n", ans);
    for (int v : vt)
        printf("%d ", v);
    puts("");
    return 0;
}