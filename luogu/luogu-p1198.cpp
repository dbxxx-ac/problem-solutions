/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-12-30 02:37:44 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-12-30 04:11:17
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
inline bool gmx(int &a, int b) {
    return b > a ? a = b, true : false;
}
inline int max(int a, int b) {
    return a > b ? a : b;
}

const int maxn = (int)2e5 + 5;
const int mlgn = 27;

int fmx[maxn][mlgn];
int lg[maxn];

int main() {
    int m = read(), d = read(), n = 0, lst = 0;
    lg[1] = 0;
    for (int i = 2; i <= m; ++i)
        lg[i] = lg[i >> 1] + 1;
    
    while (m--) {
        char op = rech();
        int x = read();
        if (op == 'A') {
            (x += lst) %= d;
            ++n;
            fmx[n][0] = x;
            for (int j = 1; (1 << j) <= n; ++j) {
                int i = n - (1 << j) + 1;
                fmx[i][j] = max(fmx[i][j - 1], fmx[i + (1 << (j - 1))][j - 1]);
            }
        } else {
            int l = n - x + 1, s = lg[x];
            lst = max(fmx[l][s], fmx[n - (1 << s) + 1][s]);
            printf("%d\n", lst);
        }
    }
    return 0;
}