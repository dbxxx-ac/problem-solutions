/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-11-17 08:32:14 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-11-17 08:48:41
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

const int maxn = (int)1e5 + 5;
int a[maxn], b[maxn];

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i)
        b[read()] = i;
    for (int i = 1; i <= n; ++i)
        a[i] = b[read()];
    
    std :: vector <int> low = {a[1]};

    for (int i = 2; i <= n; ++i) {
        if (a[i] > low.back())
            low.push_back(a[i]);
        else
            *(std :: lower_bound(low.begin(), low.end(), a[i])) = a[i];
    }

    printf("%d\n", (int)low.size());
    return 0;
}