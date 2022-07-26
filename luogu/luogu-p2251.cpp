/*
 * @Author: crab-in-the-northeast 
 * @Date: 2021-02-20 10:55:30 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2021-02-20 10:59:04
 */
#include <bits/stdc++.h>
inline int read() {
    int x = 0;
    bool flag = true;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            flag = false;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if (flag)
        return x;
    return ~(x - 1);
}

const int maxn = 1000005;
int a[maxn];

std :: deque <std :: pair <int, int> > MinQ;

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    
    for (int i = 1; i <= n; ++i) {
        while (!MinQ.empty() && MinQ.back().first >= a[i])
            MinQ.pop_back();
        MinQ.push_back(std :: make_pair(a[i], i));
        if (MinQ.front().second == i - m)
            MinQ.pop_front();
        if (i >= m)
            std :: printf("%d\n", MinQ.front().first);
    }

    return 0;
}