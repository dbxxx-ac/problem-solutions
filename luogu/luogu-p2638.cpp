/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-02 11:39:58 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-02 11:46:14
 */
#include <iostream>
#include <cstdio>

typedef unsigned long long ull;

const int maxa = 55;
const int maxb = 55;
ull C[maxa][maxb];

void makeC(int n) {
    C[0][0] = C[1][0] = C[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
}

int main() {
    int n, a, b;
    ull ans = 0;
    std :: scanf("%d %d %d", &n, &a, &b);
    makeC(50);
    for (int i = 0; i <= a; ++i)
        for (int j = 0; j <= b; ++j)
            ans += C[n - 1 + i][n - 1] * C[n - 1 + j][n - 1];
    std :: printf("%llu\n", ans);
    return 0;
}