/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-07-09 00:13:25 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-07-09 01:03:27
 */
#include <iostream>
#include <cstdio>
#include <queue>

const int maxx = 1e5 + 5;
int nation[maxx];

struct node {
    int x;
    int t;
};

std :: queue <node> q;
int main() {
    int n, ans = 0;
    std :: cin >> n;
    for (int i = 1; i <= n; ++i) {
        int t, m;
        std :: cin >> t >> m;
        while (!q.empty()) {
            node now = q.front();
            if (now.t + 86400 <= t) {
                if (!--nation[now.x]) --ans;
                q.pop();
            } else break;
        }

        for (int j = 1; j <= m; ++j) {
            int x;
            std :: cin >> x;
            node now;
            now.x = x;
            now.t = t;
            q.push(now);
            if ((++nation[x]) == 1) ++ans;
        }

        std :: cout << ans << std :: endl;
    }

    return 0;
}