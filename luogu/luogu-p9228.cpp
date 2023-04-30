/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-22 15:27:11 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-22 18:47:26
 */
#include <bits/stdc++.h>
#define int long long
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

const int maxn = (int)1e6 + 5;
int a[maxn];
std :: deque <int> A;

signed main() {
    int n = read(), m = read(), k = read(), ans = 0;
    for (int i = 1; i <= n; ++i)
        a[i] = read(), ans += a[i];
    for (int i = 1; i <= m; ++i)
        ans += read();
    
    std :: sort(a + 1, a + 1 + n, std :: greater <int> ());
    
    for (int i = 1; i <= n; ++i)
        A.push_back(a[i]);
    
    while (!A.empty() && m) {
        if (A.front() > k) {
            ans += A.front();
            A.pop_front();
        } else {
            ans += k;
            A.pop_back();
        }
        --m;
    }

    printf("%lld\n", ans);
    return 0;
}