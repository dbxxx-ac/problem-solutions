/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-28 07:57:44 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-28 08:11:36
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
double a[maxn], b[maxn];

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i)
        scanf("%lf%lf", &a[i], &b[i]);
    std :: sort(a + 1, a + 1 + n, std :: greater <double> ());
    std :: sort(b + 1, b + 1 + n, std :: greater <double> ());
    
    std :: partial_sum(a + 1, a + 1 + n, a + 1);
    std :: partial_sum(b + 1, b + 1 + n, b + 1);

    double ans = 0;
    
    for (int p = 1, q = 0; p <= n && q <= n;) {
        ans = std :: max(ans, std :: min(a[p], b[q]) - p - q);
        if (a[p] <= b[q])
            ++p;
        else
            ++q;
    }

    printf("%.4lf\n", ans);
    return 0;
}