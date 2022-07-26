/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-11-06 16:41:35 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2021-02-23 10:51:12
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
int a[maxn << 2], n;

inline int lowbit(int x) {
    return x & (-x);
}

int getsum(int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        sum += a[i];
    return sum;
}

void update(int x, int val) {
    for (int i = x; i <= n; i += lowbit(i))
        a[i] += val;
}

int main() {
    n = read();
    int m = read();
    for (int i = 1; i <= n; ++i)
        update(i, read());
    while (m--) {
        int op = read();
        if (op == 1) {
            int x = read(), val = read();
            update(x, val);
        } else {
            int l = read(), r = read();
            std :: printf("%d\n", getsum(r) - getsum(l - 1));
        }
    }
    return 0;
}