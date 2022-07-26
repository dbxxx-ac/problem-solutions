/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-06-13 10:58:25 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-06-13 11:07:11
 */
#include <iostream>
#include <cstdio>

const int maxn = 1000005;

long n, m, a[maxn];

long read() {
    long x;
    std :: cin >> x;
    return x;
}

bool check(long h) {
    long res = 0;
    for (long i = 1; i <= n; ++i)
        if (a[i] > h)
            res += a[i] - h;
    return res >= m;
}

int main() {
    n = read();
    m = read();
    long l = 0, r = 0;
    for (long i = 1; i <= n; ++i) {
        a[i] = read();
        r = std :: max(r, a[i]);
    }
    
    while (l <= r) {
        long mid = l + r >> 1;
        if(check(mid)) l = mid + 1;
        else r = mid - 1;
    }

    std :: cout << l - 1 << std :: endl;
    return 0;
}