/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-11-16 00:44:31 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-11-16 00:47:37
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
const int maxn = (int)1e4 + 5;
inline bool gmx(int &a, int b) {
    return b > a ? a = b, true : false;
}

int f[maxn];
std :: vector <int> a[maxn];

int main() {
    int n = read(), k = read();
    while (k--)  {
        int p = read(), t = read();
        a[p].push_back(t);
    }

    for (int i = n; i; --i) {
        if (a[i].empty())
            f[i] = f[i + 1] + 1;
        else
            for (int t : a[i])
                gmx(f[i], f[i + t]);
    }

    printf("%d\n", f[1]);
    return 0;
}