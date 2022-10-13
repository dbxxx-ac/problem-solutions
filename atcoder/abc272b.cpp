/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-08 20:03:39 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-08 20:06:37
 */
#include <bits/stdc++.h>

const int maxn = 105;

bool is[maxn][maxn];

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

int tmp[maxn];

int main() {
    int n = read(), m = read();
    while (m--) {
        int k = read();
        for (int i = 1; i <= k; ++i) {
            tmp[i] = read();
            for (int j = 1; j <= i; ++j)
                is[tmp[j]][tmp[i]] = is[tmp[i]][tmp[j]] = true;
        }
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (!is[i][j]) {
                puts("No");
                return 0;
            }

    puts("Yes");
    return 0;
}