/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-08-19 01:17:15 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-08-20 01:13:22
 */
#include <iostream>
#include <cstdio>

const int maxn = 1005;
int fa[maxn], enemy[maxn];

int find(int x) {
    while (x != fa[x]) x = fa[x] = fa[fa[x]];
    return x;
}

void unite(int x, int y) {
    int fax = find(x);
    int fay = find(y);
    fa[fax] = fay;
    return ;
}

int main() {
    int n, m;
    std :: scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    
    for (int i = 1; i <= m; ++i) {
        char op;
        int p, q;
        std :: cin >> op >> p >> q;//本来这里想用std :: scanf结果因为字符原因不行，只好用cin了（哭
        if (op == 'F') unite(p, q);
        else if (op == 'E') {
            if (!enemy[q]) enemy[q] = p;
            else unite(p, enemy[q]);
            if (!enemy[p]) enemy[p] = q;
            else unite(q, enemy[p]);
        } else {
            std :: printf("DBXXX AK IOI");//NEVER THIS WAY
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (fa[i] == i)
            ++ans;

    std :: printf("%d\n", ans);
    return 0;
}