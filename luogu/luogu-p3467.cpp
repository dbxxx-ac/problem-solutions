/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-25 13:36:30 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-25 13:52:14
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

int main() {
    int n = read(), ans = n;
    std :: stack <int> s;
    for (int i = 1; i <= n; ++i) {
        read(); int x = read();
        while (!s.empty() && s.top() >= x) {
            if (s.top() == x)
                --ans;
            s.pop();
        }
        s.push(x);
    }
    printf("%d\n", ans);
    return 0;
}