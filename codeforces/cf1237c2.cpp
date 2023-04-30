/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-12-18 18:48:57 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-12-18 19:00:00
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
const int maxn = 50005;

int px[maxn], py[maxn], pz[maxn];

std :: map <int, std :: map <int, std :: map <int, int> > > B;

bool exi[maxn];

inline void del(int id) {
    int x = px[id], y = py[id], z = pz[id];
    B[x][y].erase(z);
    if (B[x][y].empty())
        B[x].erase(y);
    if (B[x].empty())
        B.erase(x);
}

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i) {
        int x = px[i] = read(), y = py[i] = read(), z = pz[i] = read();
        B[x][y][z] = i;
        exi[i] = true;
    }

    for (int i = 1; i <= n; ++i) if (exi[i]) {
        del(i);
        int x = px[i], y = py[i], z = pz[i];
        auto bx = B.lower_bound(x);
        if (bx == B.end())
            bx = std :: prev(bx);
        auto by = bx -> second.lower_bound(y);
        if (by == bx -> second.end())
            by = std :: prev(by);
        auto bz = by -> second.lower_bound(z);
        if (bz == by -> second.end())
            bz = std :: prev(bz);
        
        int p = bz -> second;
        del(p);
        exi[p] = false;
        printf("%d %d\n", p, i);
    }

    return 0;
}