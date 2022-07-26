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
    if(flag) return x;
    return ~(x - 1);
}

int solve(int a, int b) {
    if (a == 1 || b == 1)
        return a + b - 2;
    return a / b + solve(b, a % b);
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int n = read(), ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; ++i)
        if (gcd(n, i) == 1)
            ans = std :: min(ans, solve(n, i));
    printf("%d\n", ans);
    return 0;
}