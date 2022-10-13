/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-08 20:00:37 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-08 20:01:44
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



int main() {
    int n = read(), s = 0;
    for (int i = 1; i <= n; ++i)
        s += read();
    printf("%d\n", s);
    return 0;
}