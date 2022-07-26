/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-08-05 17:40:13 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-08-05 18:17:35
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>

const int maxn = 105;

int n;

struct node {
    int father, depth;
}a[maxn];

int broad[maxn];

int updis = 0, downdis = 0;
int total_depth = 0, total_broad = 0;

void getdis(int u, int v) {
    if (u == v) {
        std :: printf("%d\n", updis * 2 + downdis);
        exit(0);
    }
    if (a[u].depth == a[v].depth) {
        u = a[u].father;
        ++updis;
        v = a[v].father;
        ++downdis;
    } else if (a[u].depth > a[v].depth) {
        u = a[u].father;
        ++updis;
    } else {
        v = a[v].father;
        ++downdis;
    }
    getdis(u, v);
    return ;
}

int main() {
    std :: scanf("%d", &n);
    a[1].depth = 1;
    for (int i = 1; i < n; ++i) {
        int tmpu, tmpv;
        std :: scanf("%d%d", &tmpu, &tmpv);
        a[tmpv].father = tmpu;
        a[tmpv].depth = a[tmpu].depth + 1;
        ++broad[a[tmpv].depth];
        total_depth = std :: max(total_depth, a[tmpv].depth);
        total_broad = std :: max(total_broad, broad[a[tmpv].depth]);
    }
    std :: printf("%d\n%d\n", total_depth, total_broad);
    int tmpu, tmpv;
    std :: scanf("%d%d", &tmpu, &tmpv);
    getdis(tmpu, tmpv);
}