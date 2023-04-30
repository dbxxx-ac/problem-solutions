/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-19 13:39:46 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-19 13:43:16
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

const int maxn = 200005;

int a[maxn];

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    a[n + 1] = -1;
    std :: sort(a + 1, a + 1 + n);
    for (int r = 1, l = 1; r <= n; ++r) {
        if (a[r] != a[r + 1]) {
            printf("%d %d\n", a[r], r - l + 1);
            l = r + 1;
        }
    }
    return 0;
}