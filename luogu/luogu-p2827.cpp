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
const int mininf = 0xc0c0c0c0;
int a[maxn];

std :: queue <int> qw[4];
typedef std :: pair <int, int> pii;

int main() {
    int n = read(), m = read(), q = read(), u = read(), v = read(), t = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    std :: sort(a + 1, a + n + 1, std :: greater <int> ());
    for (int i = 1; i <= n; ++i)
        qw[1].push(a[i]);

    for (int i = 0; i < m; ++i) {
        pii p = std :: max({std :: make_pair(qw[1].empty() ? mininf : qw[1].front(), 1),
                            std :: make_pair(qw[2].empty() ? mininf : qw[2].front(), 2),
                            std :: make_pair(qw[3].empty() ? mininf : qw[3].front(), 3)});
        int x = p.first + q * i, j = p.second;
        qw[j].pop();
        
        int b = 1ll * x * u / v, c = x - b;
        qw[2].push(b - q - q * i);
        qw[3].push(c - q - q * i);

        if (i % t == t - 1)
            printf("%d ", x);
    }

    puts("");

    for (int i = 1; i <= n + m; ++i) {
        pii p = std :: max({std :: make_pair(qw[1].empty() ? mininf : qw[1].front(), 1),
                            std :: make_pair(qw[2].empty() ? mininf : qw[2].front(), 2),
                            std :: make_pair(qw[3].empty() ? mininf : qw[3].front(), 3)});
        int x = p.first, j = p.second;
        qw[j].pop();

        if (i % t == 0)
            printf("%d ", x + q * m);
    }

    puts("");
    return 0;
}