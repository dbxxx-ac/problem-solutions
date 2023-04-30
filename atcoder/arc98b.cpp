/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-26 14:52:01 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-26 15:01:46
 */
#include <bits/stdc++.h>
#define int long long
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

const int mlgn = 25;
const int lg = 19;

int lst[mlgn];

signed main() {
    int n = read(), ans = 0;
    for (int l = 1, r = 1; r <= n; ++r) {
        int x = read();
        for (int i = 0; i <= lg; ++i) {
            if (x & (1 << i)) {
                gmx(l, lst[i] + 1);
                lst[i] = r;
            }
        }

        ans += r - l + 1;
    }

    printf("%lld\n", ans);
    return 0;
}