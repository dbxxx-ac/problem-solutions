/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-29 13:55:35 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-29 14:26:12
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

int n, m, A, B;
const int maxn = 505;
const int maxm = 505;
int s[maxn][maxm];

inline int sum(int x1, int y1, int x2, int y2) {
    return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]; 
}

inline bool check2(int u, int d, int v) {
    int totb = 0;
    for (int l = 1, r = 1; r <= m; ++r) {
        if (sum(u, l, d, r) >= v) {
            l = r + 1;
            ++totb;
            if (totb >= B)
                return true;
        }
    }
    return false;
}

inline bool check(int v) {
    int tota = 0;
    for (int u = 1, d = 1; d <= n; ++d) {
        if (check2(u, d, v)) {
            u = d + 1;
            ++tota;
            if (tota >= A)
                return true;
        }
    }
    return false;
}

int main() {
    n = read(); m = read(); A = read(); B = read();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + read();
    
    int ans = 0;
    for (int i = (1 << 30); i; i >>= 1)
        if (check(ans + i))
            ans += i;
    
    printf("%d\n", ans);
    return 0;
}