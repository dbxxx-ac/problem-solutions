/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-16 17:28:19 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-16 17:58:13
 */
#include <bits/stdc++.h>
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
    if(flag)
        return x;
    return ~(x - 1);
}

const int maxn = 1.5e5 + 5;
const int maxc = 3e6 + 5;

struct segment {
    int l, r;
}a[maxn];

bool cmp(segment a, segment b) {
    return a.r < b.r;
}

int f[maxc];

inline int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i) {
        a[i].l = read();
        a[i].r = read();
    }
    
    std :: sort(a + 1, a + 1 + n, cmp);

    for (int i = 1; i <= n; ++i) {
        int j = std :: upper_bound(a + 1, a + i, (segment){0, a[i].l - 1}, cmp) - a - 1;
        f[i] = max(f[i - 1], f[j] + a[i].r - a[i].l + 1);
    }

    printf("%d\n", f[n]);
    return 0;
}