/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-20 10:37:44 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-20 10:50:53
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

const int maxn = (int)5e5 + 5;

int c[maxn];

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

int main() {
    n = read();
    int m = read();
    for (int i = 1; i <= n; ++i) {
        int x = read();
        add(i, x);
        add(i + 1, -x);
    }

    while (m--) {
        int o = read();
        if (o == 1) {
            int l = read(), r = read(), x = read();
            add(l, x);
            add(r + 1, -x);
        } else {
            int x = read();
            printf("%d\n", get(x));
        }
    }

    return 0;
}