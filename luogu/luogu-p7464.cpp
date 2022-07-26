/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-05-04 12:34:28 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-05-04 12:46:55
 */
#include <iostream>
#include <cstdio>
#include <cmath>
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
    if(flag) return x;
    return ~(x - 1);
}

const int maxn = 1e6 + 5;
int a[maxn];

int main() {
    int T = read();
    for (int i = 1; i < cbrt(maxn); ++i)
        for (int j = i + 1; j <= maxn / i; ++j)
            for (int k = j + 1; k <= maxn / i / j; ++k)
                ++a[i * j * k];
    for (int i = 2; i <= maxn; ++i)
        a[i] += a[i - 1];
    while (T--) {
        int x = read();
        printf("%d\n", a[x]);
    }
    return 0;
}