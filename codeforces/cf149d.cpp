/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-11-23 17:19:37 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-11-23 17:55:13
 */
#include <bits/stdc++.h>
#define int long long
inline std :: pair <std :: string, int> rest(bool space = true) {
    std :: string s;
    char ch = getchar();
    for (; !isgraph(ch); ch = getchar());
    for (; isgraph(ch); ch = getchar())
        s.push_back(ch);
    return {space ? " " + s : s, s.length()};
}

const int maxn = 705;
const int mod = (int)1e9 + 7;
std :: string s;

int f[maxn][maxn][3][3];
int p[maxn];

void sol(int l, int r) {
    if (r == l + 1) {
        f[l][r][0][1] = f[l][r][1][0] = f[l][r][0][2] = f[l][r][2][0] = 1;
        return ;
    }
    if (r == p[l]) {
        sol(l + 1, r - 1);
        f[l][r][0][1] = f[l][r][0][2] = (
            f[l + 1][r - 1][0][0] + f[l + 1][r - 1][0][2] + 
            f[l + 1][r - 1][1][0] + f[l + 1][r - 1][1][2] + 
            f[l + 1][r - 1][2][0] + f[l + 1][r - 1][2][2]) % mod;
        f[l][r][1][0] = f[l][r][2][0] = (
            f[l + 1][r - 1][0][0] + f[l + 1][r - 1][2][0] + 
            f[l + 1][r - 1][0][1] + f[l + 1][r - 1][2][1] + 
            f[l + 1][r - 1][0][2] + f[l + 1][r - 1][2][2]) % mod;
    } else {
        sol(l, p[l]);
        sol(p[l] + 1, r);
        
        for (int a = 0; a < 3; ++a)
        for (int b = 0; b < 3; ++b)
        for (int c = 0; c < 3; ++c)
        for (int d = 0; d < 3; ++d)
            if (!b || b != c)
                (f[l][r][a][d] += 
                (f[l][p[l]][a][b] * f[p[l] + 1][r][c][d])
                % mod) %= mod;
    }
}

signed main() {
    auto _ = rest(); s = _.first; int n = _.second;
    
    std :: stack <int> st;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '(')
            st.push(i);
        else {
            p[st.top()] = i;
            st.pop();
        }
    }

    sol(1, n);
    
    int ans = 0;
    for (int a = 0; a < 3; ++a)
        for (int b = 0; b < 3; ++b)
            (ans += f[1][n][a][b]) %= mod;
    printf("%lld\n", ans);
    return 0;
}