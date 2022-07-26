/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-23 23:31:53 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-23 23:33:50
 */

#include <iostream>
#include <cstdio>

const int maxn = 1000005;
const int maxm = 2005;

int a[maxn];
int vis[maxm];
int t;

int main() {
    int n, m, minans = 1008610086, minl = 0, minr = 0;
    std :: scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        std :: scanf("%d", &a[i]);

    vis[a[1]] = 1;
    for (int l = 1, r = 1, t = 1; l <= r && r <= n;) {
        if (t == m) {
            if (r - l + 1 < minans) {
                minans = r - l + 1;
                minl = l;
                minr = r;
            }
            --vis[a[l]];
            if (vis[a[l]] == 0)
                --t;
            ++l;
        } else {
            ++r;
            if (vis[a[r]] == 0)
                ++t;
            ++vis[a[r]];
        }
    }

    std :: printf("%d %d\n", minl, minr);
    return 0;
}