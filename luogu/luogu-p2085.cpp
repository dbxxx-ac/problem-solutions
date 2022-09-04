/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-08-07 19:37:11 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-08-07 19:58:41
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

const int maxn = 10005;

int a[maxn], b[maxn], c[maxn];

struct func {
    int id;
    int x;
};

inline int calc(int id, int x) {
    return a[id] * x * x + b[id] * x + c[id];
}

struct cmp {
    bool operator () (func a, func b) {
        return calc(a.id, a.x) > calc(b.id, b.x);
    }
};

std :: priority_queue <func, std :: vector <func>, cmp> q;

signed main() {
    int n = read(), m = read();
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
        b[i] = read();
        c[i] = read();
        q.push((func){i, 1});
    }

    while (m--) {
        int id = q.top().id, x = q.top().x;
        q.pop();
        printf("%lld ", calc(id, x));
        q.push((func){id, x + 1});
    }

    return 0;
}