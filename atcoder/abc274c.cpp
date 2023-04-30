/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-22 20:26:43 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-22 20:28:40
 */
#include <bits/stdc++.h>
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

const int maxn = (int)2e5 + 5;

int f[maxn << 1];

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i) {
        int x = read();
        f[i << 1] = f[i << 1 | 1] = f[x] + 1;
    }

    for (int i = 1; i <= (n << 1 | 1); ++i)
        printf("%d\n", f[i]);
    
    return 0;
}