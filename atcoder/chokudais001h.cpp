/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-27 17:36:25 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-02-17 19:00:42
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
inline bool gmx(int &a, int b) {
    return b > a ? a = b, true : false;
}

const int maxn = (int)1e5 + 5;

struct node {
    int v, id;
} a[maxn];

int li, bit[maxn];

inline void upd(int x, int v) {
    for (; x <= li; x += lowbit(x))
        gmx(bit[x], v);
}

inline int get(int x) {
    int ans = 0;
    for (; x; x -= lowbit(x))
        gmx(ans, bit[x]);
    return ans;
}


int main() {
    int n = read();
    li = n;
    
    for (int i = 1; i <= n; ++i) {
        int v = read();
        a[i] = (node){v, i};
    }

    std :: sort(a + 1, a + n + 1, [](node x, node y) {
        return x.v < y.v;
    });

    for (int i = 1; i <= n; ++i) {
        int id = a[i].id, v = a[i].v;
        if (i != 1 && v == a[i - 1].v)
            continue;
        upd(id, get(id) + 1);
    }

    lo;
    printf("%d\n", get(n));
    return 0;
}