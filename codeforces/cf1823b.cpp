/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-27 22:46:47 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-27 23:12:19
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

const int maxn = (int)2e5 + 5;

int main() {
    int T = read();
    while (T--) {
        int n = read(), k = read(), ans = 0;
        for (int i = 1; i <= n; ++i) {
            int x = read();
            if (x % k != i % k)
                ++ans;
        }
        if (ans == 0)
            puts("0");
        else if (ans == 2)
            puts("1");
        else
            puts("-1");
    }
    return 0;
}

/*
4 1 10 7
1 4 7 10
6 8 3
3 6 8
9 5 2
2 5 9
*/