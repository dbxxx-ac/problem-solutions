/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-21 18:28:47 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-25 19:27:54
 */
#include <bits/stdc++.h>
#define int long long
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

std :: deque <int> P;
int x;

void solve(int n) {
    if (n == 1)
        return ;
    solve(n / 2);
    P.push_back(++x);
    if (n & 1LL)
        P.push_front(++x);
    return ;
}

signed main() {
    int n = read();
    solve(n + 1);
    printf("%lld\n", (int)P.size() * 2);
    for (int i : P)
        printf("%lld ", i);
    for (int i = 0; i < (int)P.size(); ++i)
        printf("%lld ", i + 1);
    puts("");
    return 0;
}