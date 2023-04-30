/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-11-20 00:39:42 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-11-20 00:51:13
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
inline int min(int a, int b) {
    return a < b ? a : b;
}
inline bool gmx(int &a, int b) {
    return b > a ? a = b, true : false;
}
typedef std :: pair <int, int> pii;

const int maxw = (int)4e4 + 5;

int f[maxw];

int main() {
    int n = read(), m = read();

    std :: vector <pii> a;

    for (int i = 1; i <= n; ++i) {
        int w = read(), v = read(), k = min(m / v, read());
        for (int j = 1; j <= k; j <<= 1) {
            a.emplace_back(j * v, j * w);
            k -= j;
        }

        if (k)
            a.emplace_back(k * v, k * w);
    }

    for (pii p : a)
        for (int j = m, v = p.first, w = p.second; j >= v; --j)
            gmx(f[j], f[j - v] + w);
    
    printf("%d\n", f[m]);
    return 0;
}   