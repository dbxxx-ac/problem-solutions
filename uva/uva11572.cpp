/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-26 11:07:12 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-26 11:17:26
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

int main() {
    int T = read();
    while (T--) {
        int n = read(), ans = 0;
        std :: unordered_map <int, int> a;
        for (int r = 1, l = 1; r <= n; ++r) {
            int x = read();
            if (a.count(x)) {
                int lst = a[x];
                if (lst >= l)
                    l = lst + 1;
            }
            a[x] = r;
            gmx(ans, r - l + 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}