/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-07-19 22:14:55 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-07-19 22:18:39
 */
#include <iostream>
#include <cstdio>

const int maxn = 100005;

struct node {
    int l, r;
}tree[maxn];

int n, ans = 0;

void dfs(int id, int depth) {
    if (depth > ans) ans = depth;
    if (tree[id].l != 0) dfs(tree[id].l, depth + 1);
    if (tree[id].r != 0) dfs(tree[id].r, depth + 1);
    return ;
}

int main() {
    std :: cin >> n;
    for (int i = 1; i <= n; ++i) std :: cin >> tree[i].l >> tree[i].r;
    dfs(1, 1);
    std :: cout << ans << std :: endl;
    return 0;
}