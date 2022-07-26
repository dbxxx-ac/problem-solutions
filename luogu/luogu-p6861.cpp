/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-20 09:26:57 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-20 09:28:27
 */
#include <iostream>
#include <cstdio>

int work(int a, int b) {
    return (a ^ b) + (a | b);
}

int main() {
    int n, ans = 0;
    std :: scanf("%d", &n);
    for (int a = 1; a <= n; ++a)
        for (int b = 1; b <= n; ++b)
            ans = ans > work(a, b) ? ans : work(a, b);
    std :: printf("%d\n", ans);
    return 0;
}