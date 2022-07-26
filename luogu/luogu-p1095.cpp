/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-16 16:27:05 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-16 16:33:33
 */
#include <bits/stdc++.h>
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
    if(flag)
        return x;
    return ~(x - 1);
}

int main() {
    int m = read(), s = read(), t = read();
    int s1 = 0, s2 = 0;
    for (int i = 1; i <= t; ++i) {
        s1 += 17;
        if (m >= 10) {
            m -= 10;
            s2 += 60;
        } else
            m += 4;
        if (s2 > s1)
            s1 = s2;
        if (s1 >= s) {
            puts("Yes");
            printf("%d\n", i);
            return 0;
        }
    }
    puts("No");
    printf("%d\n", s1);
    return 0;
}