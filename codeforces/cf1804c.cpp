/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-12 23:23:34 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-12 23:36:13
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

const int maxn = (int)1e5 + 5;

int main() {
    int T = read();
    while (T--) {
        int n = read(), x = read(), p = read();
        if (p > n * 2)
            p = n * 2;
        bool fl = false;
        for (int sum = 1, f = 1; f <= p; ++f, (sum += f) %= n) {
            if ((x + sum) % n == 0) {
                fl = true;
                break;
            }
        }
        if (fl)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}