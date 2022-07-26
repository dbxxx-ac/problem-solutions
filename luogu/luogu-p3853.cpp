/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-06-16 08:23:06 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-06-16 09:26:11
 */
#include <iostream>
#include <cstdio>

const int maxn = 100005;
int a[maxn];
int L, n, k;

bool check(int x) {
    int res = 0;
    for (int i = 1; i <= n + 1; ++i) {
        if (a[i] - a[i - 1] > x) {
            res += (a[i] - a[i - 1]) / x - ((a[i] - a[i - 1]) % x == 0);
        }
        if (res > k) return false;
    }
    return true;
}

int main() {
    std :: cin >> L >> n >> k;
    for (int i = 1; i <= n; ++i)
        std :: cin >> a[i];
    a[0] = 0;
    a[n + 1] = L;
    
    int l = 0, r = L;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    std :: cout << l << std :: endl;
    return 0;
}