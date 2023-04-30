/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-24 19:49:57 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-24 20:09:39
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
typedef std :: pair <int, int> pii;

signed main() {
    int n = read();
    std :: stack <pii> s;

    int ans = 0;
    while (n--) {
        int x = read();
        while (!s.empty() && s.top().first < x) {
            ans += s.top().second;
            s.pop();
        }
        if (s.empty())
            s.push({x, 1});
        else if (s.top().first == x) {
            int cnt = s.top().second;
            ans += cnt;
            s.pop();
            ans += (s.empty() ? 0 : 1);
            s.push({x, cnt + 1});
        } else {
            ++ans;
            s.push({x, 1});
        }
    }
    printf("%lld\n", ans);
    return 0;
}