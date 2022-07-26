/*
 * @Author: crab-in-the-northeast 
 * @Date: 2021-07-23 09:27:03 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2021-07-23 09:36:22
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
    if (flag)
        return x;
    return ~(x - 1);
}

int main() {
    int a = 0;
    int b = (1 << 30) - 1;
    int n = read(), m = read();
    for (int i = 1; i <= n; ++i) {
        char op[10];
        scanf("%s", op);
        int t = read();
        if (op[0] == 'A') {
            a &= t;
            b &= t;
        } else if (op[0] == 'O') {
            a |= t;
            b |= t;
        } else {
            a ^= t;
            b ^= t;
        }
    }

    int ans = 0;
    for (int i = 29; i >= 0; --i) {
        if (a & (1 << i))
            ans += 1 << i;
        else if (b & (1 << i) && m >= (1 << i)) {
            ans += 1 << i;
            m -= 1 << i;
        }
    }

    printf("%ld\n", ans);
    return 0;
}