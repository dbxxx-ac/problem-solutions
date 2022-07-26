/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-21 22:39:05 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-21 22:47:17
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

const int maxn = 50005;
int a[maxn], l[maxn], r[maxn];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n, k;
    std :: scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i)
        std :: scanf("%d", &a[i]);

    l[1] = r[n] = 1;
    std :: sort(a + 1, a + n + 1);
    for (int i = 2, j = 1; i <= n; ++i) {
        while (a[i] - a[j] > k)
            ++j;
        l[i] = max(l[i - 1], i - j + 1);
    }

    for (int i = n - 1, j = n; i >= 1; --i) {
        while (a[j] - a[i] > k)
            --j;
        r[i] = max(r[i + 1], j - i + 1);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, l[i] + r[i + 1]);
    std :: printf("%d\n", ans);
    return 0;
}