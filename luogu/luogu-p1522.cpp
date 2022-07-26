/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-25 11:20:58 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-25 12:39:18
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

const int maxn = 155;

double a[maxn][maxn];
double x[maxn], y[maxn];

char s[maxn];

const double maxinf = DBL_MAX / 3.0;

int c[maxn], n;

double far[maxn], d[maxn];

void dfs(int u, int col) {
    c[u] = col;
    for (int v = 1; v <= n; ++v)
        if (c[v] == 0 && a[u][v] < maxinf)
            dfs(v, col);
}

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        x[i] = read();
        y[i] = read();
    }

    for (int i = 1; i <= n; ++i) {
        scanf("%s", s + 1);
        for (int j = 1; j <= n; ++j)
            if (s[j] == '1' || i == j)
                a[i][j] = hypot(x[i] - x[j], y[i] - y[j]);
            else
                a[i][j] = maxinf;
    }

    int idx = 0;
    for (int i = 1; i <= n; ++i)
        if (c[i] == 0)
            dfs(i, ++idx);
    
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (a[i][j] > a[i][k] + a[k][j])
                    a[i][j] = a[i][k] + a[k][j];
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            if (a[i][j] < maxinf && far[i] < a[i][j])
                far[i] = a[i][j];
        if (d[c[i]] < far[i])
            d[c[i]] = far[i];
    }

    double ans = maxinf;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (c[i] == c[j])
                continue;
            double nowd = std :: max(
                std :: max(d[c[i]], d[c[j]]),
                far[i] + far[j] + hypot(x[i] - x[j], y[i] - y[j])
            );
            if (ans > nowd)
                ans = nowd;
        }
    }

    printf("%.6lf\n", ans);
    return 0;
}