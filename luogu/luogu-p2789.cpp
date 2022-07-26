/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-01 16:31:37 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-01 16:39:52
 */
#include <iostream>
#include <cstdio>

const int maxans = 1000005;
bool vis[maxans];
int ans;

void solve(int n, int num) {
    if (n == 0) {
        if (!vis[num]) {
            vis[num] = true;
            ++ans;
        }
        return ;
    }

    for (int i = 1; i <= n; ++i)
        solve(n - i, i * (n - i) + num);
}

int main() {
    int n;
    std :: scanf("%d", &n);
    solve(n, 0);
    std :: printf("%d\n", ans);
    return 0;
}