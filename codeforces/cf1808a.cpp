/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-29 17:10:11 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-29 17:23:39
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
inline bool gmi(int &a, int b) {
    return b < a ? a = b, true : false;
}

const int maxn = (int)1e6 + 5;
const int n = (int)1e6;

int d[maxn];

int main() {
    for (int i = 1; i <= n; ++i) {
        int mx = i % 10, mn = i % 10;
        int j = i;
        while (j) {
            gmx(mx, j % 10);
            gmi(mn, j % 10);
            j /= 10;
        }
        d[i] = mx - mn;
    }

    int T = read();
    while (T--) {
        int l = read(), r = read(), ans = l;
        for (int i = l; i <= r; ++i)
            if (d[i] == 9) {
                ans = i;
                break;
            } else if (d[i] > d[ans])
                ans = i;
        printf("%d\n", ans);
    }
    return 0;
}