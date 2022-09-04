/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-09-03 16:38:02 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-09-03 17:03:10
 */
#include <bits/stdc++.h>
#define int unsigned long long

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

const int maxk = 67;
bool nut[maxk];

signed main() {
    int n = read(), m = read(), _ = read(), k = read();
    int f = 0;

    if (n == 0 && m == 0 && k == 64) {
        puts("18446744073709551616");
        return 0;
    }
    
    for (int i = 1; i <= n; ++i)
        f |= read();

    for (int i = 1; i <= m; ++i) {
        int p = read(); _ = read();
        if (f & (1ULL << p))
            continue;
        if (nut[p])
            continue;
        nut[p] = true;
        --k;
    }

    printf("%llu\n", (1ULL << k) - n);
    return 0;
}