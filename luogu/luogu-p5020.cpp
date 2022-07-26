/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-11-05 11:28:47 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-11-05 12:12:35
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

const int maxn = 105;
const int maxnum = 25005;
int a[maxn];
int needed[maxnum];

int main() {
    int T;
    std :: scanf("%d", &T);
    while (T--) {
        int n;
        std :: scanf("%d", &n);
        std :: memset(needed, -1, sizeof(needed));
        for (int i = 1; i <= n; ++i) {
            std :: scanf("%d", &a[i]);
            needed[a[i]] = 1;
        }
        std :: sort(a + 1, a + 1 + n);
        for (int i = 1; i <= a[n]; ++i)
            if (needed[i] >= 0) {
                for (int j = 1; j <= n; ++j)
                    if (i + a[j] <= a[n])
                        needed[i + a[j]] = 0;
                    else
                        break;
            }
        int ans = 0;
        for (int i = 1; i <= a[n]; ++i)
            if (needed[i] == 1)
                ++ans;
        std :: printf("%d\n", ans);
    }
    return 0;
}