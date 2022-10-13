/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-09-27 09:21:24 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-09-27 09:45:09
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

const int maxn = (int)5e5 + 5;
const int lgn = 20;

int a[maxn], b[maxn], nxt[maxn][lgn];

int main() {
    int n = read(), q = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    for (int i = 1; i <= n; ++i)
        b[i] = read();
    
    std :: stack <int> s;
    for (int i = 1; i <= n; ++i) {
        while (!s.empty()) {
            int x = s.top();
            if (a[i] == a[x] || b[i] >= b[x]) {
                nxt[x][0] = i;
                s.pop();
            } else
                break;
        }
        s.push(i);
    }
    
    while (!s.empty()) {
        int x = s.top();
        nxt[x][0] = n + 1;
        s.pop();
    }

    nxt[n + 1][0] = n + 1;
    
    for (int d = 1; d < lgn; ++d)
        for (int i = 1; i <= n + 1; ++i)
            nxt[i][d] = nxt[nxt[i][d - 1]][d - 1];
    
    while (q--) {
        int l = read(), r = read();
        int ans = 1;
        for (int d = lgn - 1; d >= 0; --d) {
            if (nxt[l][d] <= r) {
                ans += 1 << d;
                l = nxt[l][d];
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}