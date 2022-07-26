/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-01 12:24:55 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-01 12:26:34
 */
#include <iostream>
#include <cstdio>

int main() {
    int n, ans = 0;
    std :: scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x;
        std :: scanf("%d", &x);
        ans ^= x;
    }
    std :: printf("%d\n", ans);
    return 0;
}