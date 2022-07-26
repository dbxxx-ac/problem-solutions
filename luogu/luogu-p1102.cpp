/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-06-13 10:29:10 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-06-13 10:37:59
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

inline long read() {
    long x;
    std :: cin >> x;
    return x;
}

const int maxn = 200005;

long a[maxn];

int main() {
    long n = read(), c = read(), ans = 0;
    for (int i = 1; i <= n; ++i) a[i] = read();
    std :: sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) 
        ans += (std :: upper_bound(a + 1, a + n + 1, a[i] + c) - a) - (std :: lower_bound(a + 1, a + n + 1, a[i] + c) - a);
    std :: cout << ans << std :: endl;
    return 0;
}