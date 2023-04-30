/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-26 09:40:23 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-26 09:53:40
 */
#include <bits/stdc++.h>
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
inline int lowbit(int x) {
    return x & (-x);
}

const int maxn = 305, maxm = 305, maxc = 105;

int fwk[maxn][maxm][maxc];
int a[maxn][maxm];
int n, m;

inline void add(int x, int y, int c, int v) {
    for (int i = x; i <= n; i += lowbit(i))
        for (int j = y; j <= m; j += lowbit(j))
            fwk[i][j][c] += v;
}

inline int get(int x, int y, int c) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i))
        for (int j = y; j; j -= lowbit(j))
            ans += fwk[i][j][c];
    return ans;
}

int main() {
    n = read();
    m = read();

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int c = read();
            add(i, j, c, 1);
            a[i][j] = c;
        }
    }
    
    int q = read();
    while (q--) {
        int o = read();
        if (o == 1) {
            int x = read(), y = read(), c = a[x][y];
            add(x, y, c, -1);
            a[x][y] = c = read();
            add(x, y, c, 1);
        } else if (o == 2) {
            int x1 = read(), x2 = read(), y1 = read(), y2 = read(), c = read();
            printf("%d\n", 
            get(x2, y2, c)
            - get(x1 - 1, y2, c)
            - get(x2, y1 - 1, c)
            + get(x1 - 1, y1 - 1, c));
        }
    }

    return 0;
}