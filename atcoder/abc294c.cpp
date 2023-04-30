/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-19 20:06:42 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-19 20:10:19
 */
#include <bits/stdc++.h>
inline int read() {
    int x = 0;
    bool f = true;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            f = false;
    for (; isdigit(ch); ch = getchar())
        x = (x << 1) + (x << 3) + ch - '0';
    return f ? x : (~(x - 1));
}

const int maxn = (int)1e5 + 5;
const int maxm = (int)1e5 + 5;

struct node {
    int id;
    int rnk;
    int x;
} a[maxn + maxm];

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= n + m; ++i) {
        a[i].id = i;
        a[i].x = read();
    }
    std :: sort(a + 1, a + 1 + n + m, [](node x, node y) {
        return x.x < y.x;
    });

    for (int i = 1; i <= n + m; ++i)
        a[i].rnk = i;
    
    std :: sort(a + 1, a + 1 + n + m, [](node x, node y) {
        return x.id < y.id;
    });

    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i].rnk);
    puts("");
    for (int i = 1; i <= m; ++i)
        printf("%d ", a[i + n].rnk);
    puts("");
    return 0;
}