/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-20 10:23:53 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-20 10:28:44
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

int c[maxn];

inline int lowbit(int x) {
    return x & (-x);
}

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
    }

    while (m--) {
        int o = read();
        if (o == 1) {
            int x = read(), v = read();
            add(x, v);
        } else {
            int l = read(), r = read();
            printf("%d\n", get(r) - get(l - 1));
        }
    }

    return 0;
}