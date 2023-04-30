/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-20 17:43:24 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-20 18:10:01
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
inline int lowbit(int x) {
    return x & (-x);
}

const int maxn = (int)1e6 + 5;
const int maxq = (int)1e6 + 5;
const int maxv = (int)1e6 + 5;

int a[maxn], lst[maxv], c[maxn];

int n;
inline void add(int x, int v) {
    for (; x <= n; x += lowbit(x))
        c[x] += v;
    return ;
}

inline int get(int x) {
    int sum = 0;
    for (; x; x -= lowbit(x))
        sum += c[x];
    return sum;
}

typedef std :: pair <int, int> pii;
std :: vector <pii> qst[maxn];
int ans[maxq];

int main() {
    n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    
    std :: fill(lst + 1, lst + maxv - 3, n + 1);
    
    int q = read();

    for (int i = 1; i <= q; ++i) {
        int l = read(), r = read();
        qst[r].emplace_back(l, i);
    }

    for (int r = 1; r <= n; ++r) {
        int x = a[r];
        add(lst[x], -1);
        add(r, 1);
        lst[x] = r;
        
        for (pii q : qst[r]) {
            int l = q.first, id = q.second;
            ans[id] = get(r) - get(l - 1);
        }
    }

    for (int i = 1; i <= q; ++i)
        printf("%d\n", ans[i]);
    
    return 0;
}