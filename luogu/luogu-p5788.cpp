/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-12-30 02:27:56 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-12-30 02:31:37
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
typedef std :: pair <int, int> pii;

const int maxn = (int)3e6 + 5;
int ans[maxn];

int main() {
    int n = read();
    std :: stack <pii> s;

    for (int i = 1; i <= n; ++i) {
        int x = read();
        while (!s.empty() && x > s.top().first) {
            ans[s.top().second] = i;
            s.pop();
        }
        s.push({x, i});
    }

    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
    puts("");
    return 0;
}