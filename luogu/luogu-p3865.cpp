/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-11-04 13:08:42 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-11-04 13:27:02
 */
#include <iostream>
#include <cstdio>
#include <cmath>

const int maxn = 100005;
const int maxlogn = 25;

inline int read() {
    char ch = getchar();
    int x = 0, f = 1;
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

inline int max(int a, int b) {
    return a > b ? a : b;
}

int Max[maxn][maxlogn];

int query(int l, int r) {
    int k = log2((double)(r - l + 1));
    return max(Max[l][k], Max[r - (1 << k) + 1][k]);
}

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        Max[i][0] = read();
    for (int j = 1; j <= maxlogn; ++j)
        for (int i = 1; i <= n - (1 << j) + 1; ++i)
            Max[i][j] = max(Max[i][j - 1], Max[i + (1 << (j - 1))][j - 1]);
    
    while (m--) {
        int l = read(), r = read();
        std :: printf("%d\n", query(l, r));
    }

    return 0;
}