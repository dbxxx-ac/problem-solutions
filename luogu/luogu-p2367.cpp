/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-29 11:34:16 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-29 11:37:15
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

const int maxn = (int)5e6 + 5;
int d[maxn];

int main() {
    int n = read(), p = read();
    for (int i = 1; i <= n; ++i) {
        int v = read();
        d[i] += v;
        d[i + 1] -= v;
    }
    while (p--) {
        int l = read(), r = read(), v = read();
        d[l] += v;
        d[r + 1] -= v;
    }

    std :: partial_sum(d + 1, d + 1 + n, d + 1);
    printf("%d\n", *std :: min_element(d + 1, d + 1 + n));
    return 0;
}