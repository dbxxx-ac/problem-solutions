/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-09-06 13:22:06 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-09-06 14:01:17
 */
#include <iostream>
#include <cstdio>
#include <unordered_map>

std :: unordered_map <int, bool> m;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

int main() {
    int T;
    T = read();
    while (T--) {
        int n;
        n = read();
        m.clear();
        while (n--) {
            int x;
            x = read();
            if (!m[x]) {
                std :: printf("%d ", x);
                m[x] = true;
            }
        }
        putc('\n', stdout);
    }
    return 0;  
}