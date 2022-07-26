/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-09-16 12:13:33 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-09-19 10:46:20
 */
#include <iostream>
#include <cstdio>
#include <vector>

const int maxn = 100005;

int A[maxn];
std :: vector <int> rev_side[maxn];

void dfs(int u, int num) {
    A[u] = num;
    for (int i = 0; i < rev_side[u].size(); ++i) {
        int v = rev_side[u][i];
        if (!A[v])
            dfs(v, num);
    }
}

int main() {
    int n, m;
    std :: scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        std :: scanf("%d %d", &u, &v);
        rev_side[v].push_back(u);
    }

    for (int i = n; i; --i) {
        if (!A[i])
            dfs(i, i);
    }
    
    for (int i = 1; i <= n; ++i)
        std :: printf("%d ", A[i]);
    putc('\n', stdout);
    return 0;
}

