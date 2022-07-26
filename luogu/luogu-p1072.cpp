/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-02 19:45:22 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-02 19:54:26
 */
#include <iostream>
#include <cstdio>

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int T;
    std :: scanf("%d", &T);
    while (T--) {
        int a0, a1, b0, b1, ans = 0;
        std :: scanf("%d %d %d %d", &a0, &a1, &b0, &b1);
        for (int i = 1; i * i <= b1; ++i) {
            if (b1 % i == 0) {
                if (i % a1 == 0 && gcd(a0 / a1, i / a1) == 1 && gcd(b1 / b0, b1 / i) == 1) ++ans;
                if (b1 != i * i) {
                    if ((b1 / i) % a1 == 0 && gcd(a0 / a1, b1 / i / a1) == 1 && gcd(b1 / b0, i) == 1) ++ans;
                }
            }
        }
        std :: printf("%d\n", ans);
    }
    return 0;
}