/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-14 21:10:58 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-15 10:59:19
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

const int maxn = 1e5 + 5;
const int maxp = 1e5 + 5; // m1
const int maxq = 1e5 + 5; // m2

struct event {
    int t;
    int id;
    bool in;
    void set(int _t, int _id, bool _in) {
        this -> t = _t;
        this -> id = _id;
        this -> in = _in;
    }
}a[maxp * 2], b[maxq * 2];

bool cmp(event a, event b) {
    return a.t < b.t;
}

int bra[maxp], brb[maxq];
int ansa[maxn], ansb[maxn];

std :: priority_queue <int, std :: vector <int>, std :: greater <int> > blst;

inline int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n = read(), p = read(), q = read();
    for (int i = 1; i <= p; ++i) {
        int x = read(), y = read();
        a[i * 2 - 1].set(x, i, true);
        a[i * 2].set(y, i, false);
    }
    for (int i = 1; i <= q; ++i) {
        int x = read(), y = read();
        b[i * 2 - 1].set(x, i, true);
        b[i * 2].set(y, i, false);
    }

    std :: sort(a, a + 1 + p * 2, cmp);
    std :: sort(b, b + 1 + q * 2, cmp);
    
    int cnt = 0;
    for (int i = 1; i <= p * 2; ++i) {
        if (a[i].in) {
            if (blst.empty()) {
                ++cnt;
                bra[a[i].id] = cnt;
                if (cnt <= n)
                    ++ansa[cnt];
            } else {
                int x = blst.top();
                blst.pop();
                bra[a[i].id] = x;
                if (x <= n)
                    ++ansa[x];
            }
        } else
            blst.push(bra[a[i].id]);
    }

    while (!blst.empty())
        blst.pop();
    
    cnt = 0;
    for (int i = 1; i <= q * 2; ++i) {
        if (b[i].in) {
            if (blst.empty()) {
                ++cnt;
                brb[b[i].id] = cnt;
                if (cnt <= n)
                    ++ansb[cnt];
            } else {
                int x = blst.top();
                blst.pop();
                brb[b[i].id] = x;
                if (x <= n)
                    ++ansb[x];
            }
        } else
            blst.push(brb[b[i].id]);
    }

    for (int i = 2; i <= n; ++i) {
        ansa[i] += ansa[i - 1];
        ansb[i] += ansb[i - 1];
    }

    int maxans = 0;
    for (int i = 0; i <= n; ++i)
        maxans = max(maxans, ansa[i] + ansb[n - i]);
    
    printf("%d\n", maxans);
    return 0;
}

/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/