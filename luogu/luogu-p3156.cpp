/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-07-08 10:30:37 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-07-08 10:34:12
 */
#include <iostream>
#include <cstdio>

const int maxn = 2e6;

int a[maxn];

int main() {
    int n, m;
    std :: cin >> n >> m;
    for (int i = 1; i <= n; ++i) std :: cin >> a[i];
    for (int i = 1; i <= m; ++i) {
        int x;
        std :: cin >> x;
        std :: cout << a[x] << std :: endl;
    }
    return 0;
}