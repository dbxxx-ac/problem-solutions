/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-06-16 01:01:11 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-06-16 01:06:58
 */
#include <iostream>
#include <cstdio>

const int maxn = 100005;
int n, k;
int a[maxn];

bool check(int l) {
    int res = 0;
    for (int i = 1; i <= n; ++i)
        res += a[i] / l;
    return res >= k;
}

int main() {
    std :: cin >> n >> k;

    int l = 0, r = 0, sum = 0;
    for (int i = 1; i <= n; ++i) {
        std :: cin >> a[i];
        sum += a[i];
    }
    if (sum / k < 1) {
        std :: cout << 0 << std :: endl;
        return 0;
    }
    r = sum / k;
    
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }

    std :: cout << l - 1 << std :: endl;
    return 0;
}
