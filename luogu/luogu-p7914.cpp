/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-09-02 11:02:16 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-09-02 12:27:28
 */
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

const int maxn = 505;
const int mod = (1e9) + 7;

int f[maxn][maxn][7];

/*
0: 纯 *
1: 开头为 (，结尾为 )，并且直接匹配
2: 开头为 *，结尾为 )
3: 开头为 (，结尾为 *
4: 开头为 (，结尾为 )（包含 1）
5: 开头为 *，结尾为 *（包含 0）
*/

char s[maxn];

inline bool eq(int i, char t) {
    return (s[i] == t) || (s[i] == '?');
}

signed main() {
    int n = read(), k = read();
    scanf("%s", s + 1);

    for (int i = 1; i <= n; ++i) {
        f[i][i - 1][0] = 1;
        f[i][i][0] = eq(i, '*') ? 1 : 0;
    }
    
    for (int len = 2; len <= n; ++len) {
        for (int l = 1, r = len; r <= n; ++l, ++r) {
            if (len <= k && f[r][r][0] == 1)
                f[l][r][5] = f[l][r][0] = f[l][r - 1][0];
            if (eq(l, '(') && eq(r, ')'))
                f[l][r][4] = f[l][r][1] = (f[l + 1][r - 1][0] + f[l + 1][r - 1][2] + f[l + 1][r - 1][3] + f[l + 1][r - 1][4]) % mod;
            for (int i = l; i < r; ++i) {
                (f[l][r][2] += f[l][i][0] * f[i + 1][r][4]) %= mod;
                (f[l][r][3] += f[l][i][4] * f[i + 1][r][0]) %= mod;
                (f[l][r][4] += (f[l][i][3] + f[l][i][4]) * f[i + 1][r][1]) %= mod;
                (f[l][r][5] += f[l][i][2] * f[i + 1][r][0]) %= mod;
            }
        }
    }

    printf("%lld\n", f[1][n][4]);
    return 0;
}