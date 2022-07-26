/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-05-02 01:43:56 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-05-02 01:59:17
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>

const int maxn = 105;
struct coin {
    int m;
    int v;
    bool operator < (const coin &b) const {
        return (double)this -> v / (double)this -> m < (double)b.v / (double)b.m;
    }
    bool operator > (const coin &b) const {
        return (double)this -> v / (double)this -> m > (double)b.v / (double)b.m;
    }
}a[maxn];

int main() {
    int n, T;
    double ans = 0;
    std :: cin >> n >> T;
    for(int i = 1; i <= n; i++)
        std :: cin >> a[i].m >> a[i].v;
    std :: sort(a + 1, a + 1 + n, std :: greater <coin>());
    for(int i = 1; i <= n; i++) {
        if(a[i].m <= T) {
            ans += a[i].v;
            T -= a[i].m;
        } else {
            ans += (double)a[i].v * T / (double)a[i].m;
            break;
        }
    }
    printf("%.2lf", ans);
    return 0;
}