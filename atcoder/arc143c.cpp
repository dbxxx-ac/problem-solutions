/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-06-29 20:05:34 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-06-29 20:13:54
 */
#include <bits/stdc++.h>

const int maxn = 2e5 + 5;

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
    if(flag) return x;
    return ~(x - 1);
}

int main() {
    int n = read(), x = read(), y = read(), p = 0, q = 0;
    while (n--) {
        int f = read() % (x + y);
        if (f >= x)
            ++p;
        if (f >= y)
            ++q;
    }
    
    if (p != 0 && p >= q)
        puts("First");
    else
        puts("Second");
    
    return 0;
}