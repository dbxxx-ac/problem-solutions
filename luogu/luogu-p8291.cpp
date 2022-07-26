/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-05-29 10:44:35 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2022-05-29 10:44:35 
 */
#include <bits/stdc++.h>

#define int long long

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

const int maxn = (int)4e5 + 5;



