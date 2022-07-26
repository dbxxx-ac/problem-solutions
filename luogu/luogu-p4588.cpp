/*
 * @Author: crab-in-the-northeast 
 * @Date: 2021-07-11 13:00:46 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2021-07-11 13:28:10
 */
#include <iostream>
#include <cstdio>
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
    if (flag)
        return x;
    return ~(x - 1);
}

const int maxq = 100005;
long long M, val[maxq << 2];

inline int lson(int p) {
    return p << 1;
}

inline int rson(int p) {
    return (p << 1) | 1;
}

inline void update(int p) {
    val[p] = (val[lson(p)] * val[rson(p)]) % M;
}

void build(int l, int r, int p) {
    val[p] = 1;
    if (l == r)
        return ;
    int mid = l + r >> 1;
    build(l, mid, lson(p));
    build(mid + 1, r, rson(p));
    return ;
}

void modify(int l, int r, int x, int v, int p) {
    if (l == r) {
        val[p] = v;
        return ;
    }
    
    int mid = l + r >> 1;
    if (x <= mid)
        modify(l, mid, x, v, lson(p));
    else
        modify(mid + 1, r, x, v, rson(p));
    update(p);
    return ;
}

int main() {
    int t = read();
    while (t--) {
        int Q = read();
        M = read();
        build(1, Q, 1);
        for (int i = 1; i <= Q; ++i) {
            int op = read(), arg = read();
            if (op == 1) {
                modify(1, Q, i, arg, 1);
                printf("%lld\n", val[1] % M);
            } else {
                modify(1, Q, i, 1, 1);
                modify(1, Q, arg, 1, 1);
                printf("%lld\n", val[1] % M);
            }
        }
    }
    return 0;
}