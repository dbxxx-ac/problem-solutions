/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-03-09 22:53:04 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-03-10 00:04:03
 */
#include <iostream>
#include <cstdio>

const int maxn = 1000005;

int max(int a, int b) {
    return a > b ? a : b;
}

struct Node {
    int l;
    int r;
    int val;
    int size;
}node[maxn];

void getSize(int u) {
    if(node[u].l != -1) {
        getSize(node[u].l);
        node[u].size += node[node[u].l].size;
    }
    if(node[u].r != -1) {
        getSize(node[u].r);
        node[u].size += node[node[u].r].size;
    }
}

bool checkVal(int u, int v) {
    if(u == -1 && v == -1) return true;
    if(node[u].val == node[v].val && checkVal(node[u].l, node[v].r) && checkVal(node[u].r, node[v].l))
        return true;
    return false;
}

int main() {
    int n, ans = 0;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &node[i].val);
        node[i].size = 1;
    }
    for(int i = 1; i <= n; i++)
        scanf("%d%d", &node[i].l, &node[i].r);

    getSize(1);
    for(int i = 1; i <= n; i++)
        if(checkVal(node[i].l, node[i].r))
            ans = max(ans, node[i].size);
    
    printf("%d\n",ans);
    return 0;
}