/*
 * @Author: crab-in-the-northeast 
 * @Date: 2021-02-18 22:36:26 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2021-02-18 22:51:45
 */
#include <bits/stdc++.h>
inline long long read() {
    long long x = 0;
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

const int maxn = 10005;
const int maxm = 10005;

struct func_kind {
    long long a, b, c;
    long long calc(long long x) {
        return this -> a * x * x + this -> b * x + this -> c;
    }
}p[maxn];

struct func {
    int idx;
    long long x;
    long long v;
    const bool operator < (const func &b) const {
        return this -> v > b.v;
    }
    long long calc() {
        return p[this -> idx].calc(this -> x);
    }
};

std :: priority_queue <func> pq;

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= n; ++i) {
        p[i].a = read();
        p[i].b = read();
        p[i].c = read();
        func tmp;
        tmp.idx = i;
        tmp.x = 1;
        tmp.v = tmp.calc();
        pq.push(tmp);
    }

    for (int i = 1; i <= m; ++i) {
        func now = pq.top();
        std :: printf("%lld ", now.v);
        func nxt;
        nxt.idx = now.idx;
        nxt.x = now.x + 1;
        nxt.v = nxt.calc();
        pq.pop();
        pq.push(nxt);
    }

    return 0;
}