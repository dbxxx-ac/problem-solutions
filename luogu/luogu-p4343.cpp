/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-17 20:43:13 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-17 21:01:44
 */
#include <bits/stdc++.h>
#define int long long

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

const int maxn = 1e5 + 5;
int a[maxn], n;

int check(int x) {
    int ans = 0;
    for (int i = 1, code = 0; i <= n; ++i) {
        code += a[i];
        if (code < 0)
            code = 0;
        if (code >= x) {
            code = 0;
            ++ans;
        }
    }
    return ans;
}

signed main() {
    n = read();
    int k = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();

    if (check(1) < k) {
        puts("-1");
        return 0;
    }

    int ans1 = 0;
    for (int i = (1LL << 60); i >= 1; i >>= 1LL)
        if (check(ans1 + i) >= k + 1)
            ans1 += i;
    ++ans1;

    int ans2 = 0;
    for (int i = (1LL << 60); i >= 1; i >>= 1LL)
        if (check(ans2 + i) >= k)
            ans2 += i;

    if (check(ans1) != k || check(ans2) != k) {
        puts("-1");
        return 0;
    }
    printf("%lld %lld\n", ans1, ans2);
    return 0;
}