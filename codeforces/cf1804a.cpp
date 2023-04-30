/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-12 22:44:54 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2023-03-12 22:44:54 
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
    int T = read();
    while (T--) {
        int x = std :: abs(read()), y = std :: abs(read());
        if (x < y)
            std :: swap(x, y);
        if (x == y)
            printf("%d\n", x * 2);
        else
            printf("%d\n", x * 2 - 1);
    }
    return 0;
}