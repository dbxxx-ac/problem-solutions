/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-21 10:53:06 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-21 10:59:48
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
int a[maxn];
int n;

inline bool check(int x) {
    long long t = 0;
    for (int i = 0; i <= n; ++i)
        if (x > a[i])
            t += x - a[i];
    
    return t <= x;
}

int main() {
    n = read();
    for (int i = 0; i <= n; ++i)
        a[i] = read();
    
    int ans = 0;
    
    for (int i = (1 << 30); i; i >>= 1)
        if (check(ans + i))
            ans += i;
    
    printf("%d\n", ans);
    return 0;
}