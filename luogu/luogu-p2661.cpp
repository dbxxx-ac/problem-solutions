/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-11 02:09:50 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-11 02:13:01
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
    if(flag) return x;
    return ~(x - 1);
}

const int maxn = 200005;

int fa[maxn];

int get(int x, int &cnt) {
    ++cnt;
    if (fa[x] == x)
        return x;
    return get(fa[x], cnt);
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n = read(), ans = maxn;
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    for (int i = 1; i <= n; ++i) {
        int cnt = 0, v = read();
        if (get(v, cnt) == i)
            ans = min(ans, cnt);
        else
            fa[i] = v;
    }
    
    printf("%d\n", ans);
    return 0;
}