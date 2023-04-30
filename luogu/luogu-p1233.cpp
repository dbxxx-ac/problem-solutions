/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-11-20 00:21:22 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-11-20 00:26:00
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

const int maxn = 5005;

struct Stick {
    int l, w;
} a[maxn];

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i) {
        int l = read(), w = read();
        a[i] = (Stick){l, w};
    }

    std :: sort(a + 1, a + 1 + n, [](Stick a, Stick b) {
        if (a.l == b.l)
            return a.w > b.w;
        return a.l > b.l;
    });

    std :: vector <int> low = {a[1].w};

    for (int i = 2; i <= n; ++i) {
        if (a[i].w > low.back())
            low.push_back(a[i].w);
        else
            *(std :: lower_bound(low.begin(), low.end(), a[i].w)) = a[i].w;
    }

    printf("%d\n", (int)low.size());
    return 0;
}