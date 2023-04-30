/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-25 08:19:16 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-25 08:21:27
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

signed main() {
    int n = read(), ans = 0;
    std :: stack <int> s;
    while (n--) {
        int x = read();
        while (!s.empty() && s.top() <= x)
            s.pop();
        ans += s.size();
        s.push(x);
    }
    printf("%lld\n", ans);
    return 0;
}