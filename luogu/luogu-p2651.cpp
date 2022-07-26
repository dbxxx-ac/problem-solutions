/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-03 21:43:28 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-03 21:47:21
 */
#include <iostream>
#include <cstdio>

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int t;
    std :: scanf("%d", &t);
    while (t--) {
        int n, a1, a2;
        std :: scanf("%d", &n);
        std :: scanf("%d %d", &a1, &a2);
        int k = a2;
        k = a2 / gcd(a1, a2);
        for (int i = 3; i <= n; ++i) {
            int x;
            std :: scanf("%d", &x);
            k /= gcd(k, x);
        }
        if (k == 1) puts("Yes");
        else puts("No");
    }
    return 0;
}