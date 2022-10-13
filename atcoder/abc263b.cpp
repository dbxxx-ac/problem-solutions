/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-03 15:07:32 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-03 15:08:48
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

const int maxn = 55;

int f[maxn];

int main() {
    int n = read();
    for (int i = 2; i <= n; ++i) {
        int x = read();
        f[i] = f[x] + 1;
    }
    printf("%d\n", f[n]);
    return 0;
}