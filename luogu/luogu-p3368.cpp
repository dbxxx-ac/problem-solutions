/*
 * @Author: crab-in-the-northeast 
 * @Date: 2021-02-23 10:26:57 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2021-02-23 10:56:39
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
    if (flag)
        return x;
    return ~(x - 1);
}

const int maxn = 500005;
int n;
int d[maxn << 2];

inline int lowbit(int x) {
    return x & (-x);
}

void update(int x, int k) {
    for (int i = x; i <= n; i += lowbit(i))
        d[i] += k;
}

int getsum(int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        sum += d[i];
    return sum;
}

int main() {
    n = read();
    int m = read();
    int lst = 0, now;
    for (int i = 1; i <= n; ++i) {
        now = read();
        update(i, now - lst);
        lst = now;
    }

    while (m--) {
        int op = read();
        if (op == 1) {
            int x = read(), y = read(), k = read();
            update(x, k);
            update(y + 1, -k);
        } else {
            int x = read();
            printf("%d\n", getsum(x));
        }
    }

    return 0;
}