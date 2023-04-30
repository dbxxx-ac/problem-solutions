/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-01-04 03:37:15 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-01-04 04:21:13
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
inline char rech() {
    char ch = getchar();
    while (!isgraph(ch))
        ch = getchar();
    return ch;
}
inline int lowbit(int x) {
    return x & (-x);
}

const int maxn = (int)1e5 + 5;
const int maxk = (int)1e6 + 5;

struct fenwick {
    int t[maxk << 1], n = (int)2e6 + 7;

    inline void add(int x, int v) {
        x += maxk;
        for (; x <= n; x += lowbit(x))
            t[x] += v;
    }

    inline int get(int x) {
        x += maxk;
        int ans = 0;
        for (; x; x -= lowbit(x))
            ans += t[x];
        return ans;
    }
} c1, c2;

typedef std :: pair <int, int> pii;
std :: vector <pii> vec;
bool del[maxn];

const int xp = (int)1e6;

void add(int k, int op) {
    if (op == -1) {
        del[vec.size()] = true;
        vec.push_back({-1, -1});
    } else if (op == 3) {
        vec.push_back({-xp - 1, 1});
        c1.add(-xp - 1, 1);
    } else if (op == 1) {
        vec.push_back({k, 1});
        c1.add(k, 1);
    } else {
        vec.push_back({k, 2});
        c2.add(k, 1);
    }
}

int main() {
    int n = read();
    vec.push_back({0, 0});
    while (n--) {
        char c = rech();
        if (c == 'A') {
            int a = read(), b = read(), c = read();
            if (a == 0) {
                if (b <= c)
                    add(-1, -1);
                else
                    add(-1, 3);
            } else if (a > 0) {
                int k = floor(1.0 * (c - b) / a) + 1; // 大于 (c - b) / a 的最小整数
                // k <= x
                if (k > xp)
                    add(-1, -1);
                else if (k < -xp)
                    add(-1, 3);
                else
                    add(k, 1);
            } else {
                int k = ceil(1.0 * (c - b) / a) - 1; // 小于 (c - b) / a 的最大整数
                // k >= x
                if (k < -xp)
                    add(-1, -1);
                else if (k > xp)
                    add(-1, 3);
                else
                    add(k, 2);
            }
        } else if (c == 'Q') {
            int x = read();
            printf("%d\n", c1.get(x) + c2.get(xp) - c2.get(x - 1));
        } else if (c == 'D') {
            int x = read();
            if (del[x])
                continue;
            del[x] = true;
            if (vec[x].second == 1)
                c1.add(vec[x].first, -1);
            else
                c2.add(vec[x].first, -1);
        }
    }
    return 0;
}