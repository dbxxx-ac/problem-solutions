/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-01-05 12:21:31 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-01-05 12:22:40
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
inline bool gmx(int &a, int b) {
    return b > a ? a = b, true : false;
}

const int maxn = (int)2e5 + 5;
int f[maxn];

int main() {
    int n = read(), l = 1;
    for (int i = 1; i <= n; ++i) {
        int x = read();
        gmx(l, f[x] = f[x - 1] + 1);
    }
    printf("%d\n", n - l);
    return 0;
}