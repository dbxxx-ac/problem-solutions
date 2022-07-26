#include <bits/stdc++.h>

#define int long long

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

signed main() {
    int a = read(), b = read(), c = read();
    int k = std :: max(a, std :: max(b, c));
    if (k >= k * 3 - a - b - c)
        printf("%lld\n", k);
    else
        puts("-1");
    return 0;
}
