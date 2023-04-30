/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-27 23:16:08 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-27 23:50:41
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

std :: map <int, int> a;

int main() {
    int T = read();
    while (T--) {
        int n = read();
        a.clear();
        for (int i = 1; i <= n; ++i) {
            int x = read(), tmp = x;
            for (int i = 2; i * i <= x; ++i) {
                while (tmp % i == 0) {
                    tmp /= i;
                    ++a[i];
                }
            }
            if (tmp != 1)
                ++a[tmp];
        }
        
        int ans = 0, now = 0;
        for (auto i : a) {
            int p = i.first, q = i.second;
            // (q1 + 1) * (q2 + 1) * (q3 + 1) .. > 2n
            // n >= 3
            // n == 1 && q >= 2
            ans += q / 2;
            now += (q % 2) ? 1 : 0;
        }
        ans += now / 3;
        printf("%d\n", ans);
    }
    return 0;
}