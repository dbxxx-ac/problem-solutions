/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-23 19:50:53 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-23 20:10:19
 */
#include <bits/stdc++.h>
#define int long long
inline int read() {
    int x = 0;
    bool f = true;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            f = false;
    for (; isdigit(ch); ch = getchar())
        x = (x << 1) + (x << 3) + ch - '0';
    return f ? x : (~(x - 1));
}
inline void write(__int128_t x) {
    if (x > 9)
        write(x / 10);
    putchar((x % 10) ^ '0');
}

inline int lowbit(int x) {
    return x & (-x);
}
const int maxn = (int)1e6 + 5;
int a[maxn], n;
int tr[maxn];

inline int get(int x) {
    int ret = 0;
    for (; x; x -= lowbit(x))
        ret += tr[x];
    return ret;
}

inline void add(int x, int v) {
    for (; x <= n; x += lowbit(x))
        tr[x] += v;
    return ;
}

signed main() {
    n = read();
    std :: vector <int> disc;
    for (int i = 1; i <= n; ++i)
        disc.push_back(a[i] = read());
    std :: sort(disc.begin(), disc.end());
    disc.erase(std :: unique(disc.begin(), disc.end()), disc.end());
    for (int i = 1; i <= n; ++i)
        a[i] = std :: lower_bound(disc.begin(), disc.end(), a[i]) - disc.begin() + 1;
    __int128_t ans = 0;
    for (int i = n; i; --i) {
        ans += get(a[i] - 1) * i;
        add(a[i], n - i + 1);
    }
    write(ans);
    puts("");
    return 0;
}