/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-03 20:25:09 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-10-03 20:25:09 
 */
#include <iostream>
#include <cstdio>

const int maxn = 10005;
const int maxnum = 1000005;

int ans[maxn];
int cnt[maxnum];

int main() {
    int n;
    std :: scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x;
        std :: scanf("%d", &x);
        for (int j = 1; j * j <= x; ++j) {
            if (x % j == 0) {
                ++cnt[j];
                if (x != j * j) ++cnt[x / j];
            }
        }
    }

    for (int i = maxnum - 5; i >= 1; --i)
        if (ans[cnt[i]] == 0)
            ans[cnt[i]] = i;
    
    for (int i = n - 1; i >= 1; --i)
        ans[i] = ans[i + 1] > ans[i] ? ans[i + 1] : ans[i];
    
    for (int i = 1; i <= n; ++i)
        std :: printf("%d\n", ans[i]);
    return 0;
}