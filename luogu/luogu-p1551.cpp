/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-08-16 14:30:34 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-08-18 19:30:40
 */
#include <iostream>
#include <cstdio>

const int maxn = 5005;
int fa[maxn];

int find(int x) {
    while (x != fa[x]) x = fa[x] = fa[fa[x]];
    return x;
}

int main() {
    int n, m, p;
    std :: scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    
    while (m--) {
        int a, b;
        std :: scanf("%d%d", &a, &b);
        int faa = find(a);
        int fab = find(b);
        fa[faa] = fab;
    }

    while (p--) {
        int a, b;
        std :: scanf("%d%d", &a, &b);
        int faa = find(a);
        int fab = find(b);
        std :: printf("%s\n", faa == fab ? "Yes" : "No");
    }

    return 0;
}