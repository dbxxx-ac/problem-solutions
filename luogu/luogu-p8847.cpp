/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-11-12 15:57:53 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-11-12 16:00:17
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

int main() {
    int n = read(), p = 0, q = 0;
    for (int i = 1; i <= n; ++i) {
        int x = read();
        if (x == 1)
            ++p;
        else
            ++q;
    }

    for (int i = 1; i <= n; ++i) {
        if (p && q) {
            if (i & 1)
                printf("1 "), --p;
            else
                printf("-1 "), --q;
        } else {
            if (p)
                printf("1 "), --p;
            else if (q)
                printf("-1 "), --q;
        }
    }

    puts("");
    return 0;
}