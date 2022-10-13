/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-03 15:52:30 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-03 16:08:49
 */
// 不会 E，来开 F
// 首先问题显然转化为满二叉树上 dp
// 卧槽这么简单？？？、
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

const int maxn = 19;
const int maxm = (1LL << (maxn - 2));

int a[maxm][maxn], v[maxm], f[maxm];

inline bool gmx(int &a, int b) {
    return b > a ? a = b, true : false;
}

void solve(int u, int L, int R, int d) {
    if (L == R)
        return ;
    int M = L + R >> 1LL;
    int l = (u << 1), r = (u << 1 | 1);
    solve(l, L, M, d - 1);
    solve(r, M + 1, R, d - 1);
    for (int i = L; i <= M; ++i)
        v[i] += f[r];
    for (int i = M + 1; i <= R; ++i)
        v[i] += f[l];
    
    for (int i = L; i <= R; ++i)
        gmx(f[u], v[i] + a[i][d]);
}

signed main() {
    int n = read();
    for (int i = 0; i < (1 << n); ++i)
        for (int j = 1; j <= n; ++j)
            a[i][j] = read();
    
    solve(1, 0, (1 << n) - 1, n);
    printf("%lld\n", f[1]);
    return 0;
}