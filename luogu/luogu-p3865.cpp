/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-30 22:00:55 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-30 22:07:07
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

const int maxn = (int)1e5 + 5;
const int mlgn = 25;
const int maxm = (int)2e6 + 5;

int lg[maxn];
int st[maxn][mlgn];

inline int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        st[i][0] = read();
    
    for (int i = 2; i <= n; ++i)
        lg[i] = lg[i >> 1] + 1;
    
    for (int j = 1; j <= lg[n]; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    
    while (m--) {
        int l = read(), r = read();
        int s = lg[r - l + 1];
        printf("%d\n", max(st[l][s], st[r - (1 << s) + 1][s]));
    }

    return 0;
}