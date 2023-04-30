/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-27 22:39:40 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-27 22:43:43
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

int f(int n, int k) {
    for (int i = 0, j = n; i <= n; ++i, --j)
        if (i * (i - 1) / 2 + j * (j - 1) / 2 == k)
            return i;
    return -1;
}

int main() {
    int T = read();
    while (T--) {
        int n = read(), k = read();
        int x = f(n, k);
        if (x == -1)
            puts("NO");
        else {
            puts("YES");
            for (int i = 1; i <= x; ++i)
                printf("1 ");
            for (int i = x + 1; i <= n; ++i)
                printf("-1 ");
            puts("");
        }
    }
    return 0;
}