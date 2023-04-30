/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-11-19 23:57:17 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-11-20 00:13:48
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
inline std :: string rest() {
    std :: string s;
    char ch = getchar();
    for (; !isgraph(ch); ch = getchar());
    for (; isgraph(ch); ch = getchar())
        s.push_back(ch);
    return s;
}
const int maxn = 105;

int f[maxn][maxn];
const int con[6][6] = {
    {5, -1, -2, -1, -3},
    {-1, 5, -3, -2, -4},
    {-2, -3, 5, -2, -2},
    {-1, -2, -2, 5, -1},
    {-3, -4, -2, -1, -100000}
};

int cw[135];

int main() {
    int n = read();
    std :: string s = " " + rest();
    int m = read();
    std :: string t = " " + rest();

    cw['A'] = 0;
    cw['C'] = 1;
    cw['G'] = 2;
    cw['T'] = 3;
    
    for (int i = 1; i <= n; ++i)
        f[i][0] = f[i - 1][0] + con[cw[(int)s[i]]][4];
    for (int j = 1; j <= m; ++j)
        f[0][j] = f[0][j - 1] + con[cw[(int)t[j]]][4];
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int p = cw[(int)s[i]], q = cw[(int)t[j]], r = 4;
            f[i][j] = std :: max({
                f[i - 1][j - 1] + con[p][q],
                f[i - 1][j] + con[r][p],
                f[i][j - 1] + con[r][q]
            });
        }
    }

    printf("%d\n", f[n][m]);
    return 0;
}