/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-17 10:20:23 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-17 11:06:28
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
inline bool gmx(int &a, int b) {
    return b > a ? a = b, true : false;
}

const int maxn = 19;
std :: vector <int> f[1 << maxn];

int main() {
    int n = read();
    for (int i = 0; i < (1 << n); ++i)
        f[i].push_back(read());
    
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < (1 << n); ++i) {
            if (i & (1 << j)) {
                int lst = i ^ (1 << j);
                for (int x : f[lst])
                    f[i].push_back(x);
                std :: sort(f[i].begin(), f[i].end(), std :: greater <int> ());
                while (f[i].size() > 2)
                    f[i].pop_back();
            }
        }
    }

    int ans = 0;
    for (int K = 1; K < (1 << n); ++K) {
        gmx(ans, f[K][0] + f[K][1]);
        printf("%d\n", ans);
    }
    return 0;
}