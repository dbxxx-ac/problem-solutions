/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-07-07 13:08:10 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-07-08 00:42:41
 */
#include <iostream>
#include <cstdio>

int a[15], idx = 0;
int n;

void dfs(int sum, int start) {
    if (sum == n) {
        if (idx == 1) return ;
        std :: cout << a[1];
        for (int i = 2; i <= idx; ++i)
            std :: cout << '+' << a[i];
        puts("");
        return ;
    }

    for (int i = start; i <= n - sum; ++i) {
        a[++idx] = i;
        dfs(sum + i, i);
        --idx;
    }
    return ;
}

int main() {
    std :: cin >> n;
    dfs(0, 1);
    return 0;
}