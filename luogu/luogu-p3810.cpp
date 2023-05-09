/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-05-04 08:43:13 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-05-04 09:10:56
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

const int N = (int)1e5 + 5;
const int K = (int)2e5 + 5;
struct node {
    int a, b, c, cnt, ans;
} a[N], b[N];
int ans[N];


struct fenwick {
    // K!!!! not N!!
    int t[K];
    inline int lowbit(int x) {
        return x & (-x);
    }
    inline void add(int x, int v) {
        for (; x < K; x += lowbit(x))
            t[x] += v;
    }
    inline int query(int x) {
        int ans = 0;
        for (; x; x -= lowbit(x))
            ans += t[x];
        return ans;
    }
} fw;

void cdq(int l, int r) {
    if (l == r)
        return ;
    int mid = (l + r) >> 1;
    cdq(l, mid);
    cdq(mid + 1, r);
    // 注意这里 cdq 的时候必须保证序列是按照 a 升序的
    // 之后会调成按 b 排序，所以如果到最后再 cdq 还得按 a 升序调回来
    // 那还不如现在就 cdq

    auto cmp = [](node p, node q) {
        return (p.b == q.b) ? (p.c < q.c) : (p.b  < q.b);
    };
    std :: sort(a + l, a + mid + 1, cmp);
    std :: sort(a + mid + 1, a + r + 1, cmp);
    int i, j;
    for (i = l, j = mid + 1; j <= r; ++j) {
        while (i <= mid && a[i].b <= a[j].b) {
            fw.add(a[i].c, a[i].cnt);
            ++i;
        }
        a[j].ans += fw.query(a[j].c);
    }
    for (--i; i >= l; --i)
        fw.add(a[i].c, -a[i].cnt);
    return ;
}

int main() {
    int n = read(); read();
    for (int i = 1; i <= n; ++i) {
        b[i].a = read();
        b[i].b = read();
        b[i].c = read();
    }
    std :: sort(b + 1, b + 1 + n, [](node p, node q) {
        if (p.a == q.a) {
            if (p.b == q.b)
                return p.c < q.c;
            return p.b < q.b;
        }
        return p.a < q.a;
    });

    int m = 0;
    for (int i = 1, cnt = 1; i <= n; ++i, ++cnt) {
        if (b[i].a == b[i + 1].a && b[i].b == b[i + 1].b && b[i].c == b[i + 1].c)
            continue;
        a[++m] = (node){b[i].a, b[i].b, b[i].c, cnt, 0};
        cnt = 0;
    }

    cdq(1, m);
    
    for (int i = 1; i <= m; ++i)
        ans[a[i].ans + a[i].cnt - 1] += a[i].cnt;
    for (int i = 0; i < n; ++i)
        printf("%d\n", ans[i]);
    return 0;
}