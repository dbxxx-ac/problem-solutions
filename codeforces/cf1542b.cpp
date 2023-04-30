/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-14 01:41:35 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-14 01:52:57
 */

#include <bits/stdc++.h>
#define int long long

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

signed main() {
    int T = read();
    while (T--) {
        int n = read(), a = read(), b = read();
        if (a == 1) {
            if (b == 1 || n % b == 1)
                puts("Yes");
            else
                puts("No");
            continue;
        }

        bool fl = false;
        for (int X = 1; X <= n; X *= a) {
            if ((n - X) % b == 0) {
                fl = true;
                break;
            }
        }

        puts(fl ? "Yes" : "No");
    }
    return 0;
}