/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-19 20:02:35 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-19 20:03:39
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
    int h = read(), w = read();
    for (int i = 1; i <= h; ++i, puts(""))
        for (int j = 1; j <= w; ++j) {
            int x = read();
            if (x == 0)
                putchar('.');
            else
                putchar('A' + x - 1);
        }
    return 0;
}