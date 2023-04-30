/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-11-12 15:56:26 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-11-12 15:56:55
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
    int n = read();
    putchar('a');
    for (int i = 1; i < n; ++i)
        putchar('b');
    puts("");
    return 0;
}