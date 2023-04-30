/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-17 00:50:58 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-17 01:04:49
 */
#include <bits/stdc++.h>
#define int unsigned long long

inline int read() {
    int x = 0;
    bool flag = true;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-')
            flag = false;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if(flag)
        return x;
    return ~(x - 1);
}

typedef std :: pair <int, int> pii;

bool hav[11];

std :: set <int> vis;

signed main() {
    int n = read(), x = read();
    int l = 1;
    for (int i = 1; i < n; ++i)
        l *= 10;

    std :: queue <pii> q;
    q.emplace(x, 0);

    while (!q.empty()) {
        int x = q.front().first, step = q.front().second;
        q.pop();
        
        if (x >= l) {
            printf("%llu\n", step);
            return 0;
        }
        
        std :: memset(hav, false, sizeof(hav));

        int t = x;
        while (t) {
            hav[t % 10] = true;
            t /= 10;
        }

        for (int i = 2; i <= 9; ++i) if (hav[i]) {
            if (vis.count(x * i))
                continue;
            q.emplace(x * i, step + 1);
            vis.insert(x * i);
        }
    }

    puts("-1");
    return 0;
}