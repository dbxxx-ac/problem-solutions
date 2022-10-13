/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-08 20:08:38 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-08 20:15:25
 */
#include <bits/stdc++.h>

const int maxn = (int)2e5 + 5;

std :: vector <int> a, b;

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

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i) {
        int x = read();
        if (x & 1)
            a.push_back(x);
        else
            b.push_back(x);
    }

    std :: sort(a.begin(), a.end(), std :: greater <int> ());
    std :: sort(b.begin(), b.end(), std :: greater <int> ());

    if (a.size() < 2 && b.size() < 2) {
        puts("-1");
        return 0;
    } else if (a.size() < 2) {
        printf("%d\n", b[0] + b[1]);
        return 0;
    } else if (b.size() < 2) {
        printf("%d\n", a[0] + a[1]);
        return 0;
    } else {
        int x = a[0] + a[1], y = b[0] + b[1];
        printf("%d\n", x > y ? x : y);
    }
    return 0;
}