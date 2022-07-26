/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-01 14:01:33 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-01 15:11:41
 */
#include <iostream>
#include <cstdio>

const int maxn = 2005;
const int maxm = 2005;
long long c[maxn][maxm], ans[maxn][maxm];

void init(int k) {
    c[0][0] = c[1][0] = c[1][1] = 1;
    for (int i = 2; i < maxn; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % k;
            ans[i][j] = ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1];
            if (c[i][j] == 0) ++ans[i][j];
        }
        ans[i][i + 1] = ans[i][i];
    }
}

int main() {
    int t, k;
    std :: scanf("%d %d", &t, &k);
    init(k);
    while (t--) {
        int n, m;
        std :: scanf("%d %d", &n, &m);
        std :: printf("%lld\n", ans[n][m > n ? n : m]);
    }
    return 0;
}