/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-02 20:20:34 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-02 20:30:20
 */
#include <bits/stdc++.h>
#define int long long

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

int a[15];
signed main() {
    int n = read(), m = read();

    std :: iota(a + 1, a + 10, 1);
    
    int f = -1, g = -1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 9; ++j) {
            a[j] %= m;
            if (a[j] == 0) {
                f = j;
                g = i;
            }
            (a[j] *= 10) %= m;
            (a[j] += j) %= m;
        }
    }

    if (f == -1) {
        puts("-1");
        return 0;
    }
    
    for (int i = 1; i <= g; ++i)
        putchar(f + '0');
    puts("");
    return 0;
}