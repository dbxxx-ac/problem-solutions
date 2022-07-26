#include <bits/stdc++.h>
inline int read() {
    int x = 0;
    bool flag = true;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            flag = false;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if(flag)
        return x;
    return ~(x - 1);
}

const int maxn = 1005;
const int maxm = 205;
const int maxk = 205;
const int mod = 1e9 + 7;

char a[maxn], b[maxm];

int f[2][maxm][maxk][2];

int main() {
    int n = read(), m = read(), k = read();
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    
    f[0][0][0][0] = f[1][0][0][0] = 1;

    for (int t = 1, i = 1; t <= n; ++t, i ^= 1)
        for (int j = 1; j <= m; ++j)
            for (int p = 1; p <= k; ++p) {
                f[i][j][p][0] = (f[i ^ 1][j][p][0] + f[i ^ 1][j][p][1]) % mod;
                if (a[t] == b[j])
                    f[i][j][p][1] = (f[i ^ 1][j - 1][p][1] + f[i][j - 1][p - 1][0]) % mod;
                else
                    f[i][j][p][1] = 0;
            }
    
    printf("%d\n", (f[n & 1][m][k][0] + f[n & 1][m][k][1]) % mod);
    return 0;
}