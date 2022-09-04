/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-09-02 21:51:51 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-09-02 21:59:05
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
    int a = read(), b = read(), n = read();
    f[1] = f[2] = 1;
    int r = 0;
    for (int i = 3; i <= 53; ++i) {
        f[i] = (a * f[i - 1] + b * f[i - 2]) % 7;
        if (f[i] == 1 && f[i - 1] == 1) {
            r = i - 2;
            break;
        }
    }

    // printf("%d\n", r);
    int x = n % r;
    printf("%d\n", f[x ? x : r]);
    return 0;
}