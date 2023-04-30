#include <bits/stdc++.h>
#define int long long
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

int a[maxn], au[maxn], c[maxn];

int n;
inline void add(int x, int v) {
    for (; x <= n; x += lowbit(x))
        c[x] += v;
}

inline int get(int x) {
    int sum = 0;
    for (; x; x -= lowbit(x))
        sum += c[x];
    return sum;
}

signed main() {
    n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    
    std :: copy(a + 1, a + 1 + n, au + 1);
    std :: sort(au + 1, au + 1 + n);
    auto en = std :: unique(au + 1, au + 1 + n);

    int ans = 0;
    for (int i = n; i; --i) {
        int x = std :: lower_bound(au + 1, en, a[i]) - au;
        ans += get(x - 1);
        add(x, 1);
    }

    printf("%lld\n", ans);
    return 0;
}