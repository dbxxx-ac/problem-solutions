/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-02 21:21:29 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-02-17 20:22:20
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

const int maxn = (int)3e5 + 5;
int b[maxn], a[maxn];

int lo[maxn], f[maxn];

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i)
        b[i] = read();
    for (int i = 1; i <= n; ++i) {
        int x = read();
        a[x] = b[i];
    }

    std :: memset(lo, 0x3f, sizeof(lo));
    int ans = 0;

    for (int i = 1; i <= n; ++i) {
        // printf("%d\n", a[i]);
        int j = std :: lower_bound(lo + 1, lo + 1 + n, a[i]) - lo;
        if (ans < j)
            ans = j;
        lo[j] = a[i];
    }

    printf("%d\n", n + ans);
    return 0;
}