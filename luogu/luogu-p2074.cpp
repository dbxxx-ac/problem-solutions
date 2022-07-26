/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-05-03 22:29:04 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-05-03 22:37:30
 */

#include <iostream>
#include <cstdio>
#include <cmath>

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
    if(flag) return x;
    return ~(x - 1);
}


double dis(int x3, int y3, int x4, int y4) {
    return std :: sqrt((x4 - x3) * (x4 - x3) + (y4 - y3) * (y4 - y3));
}

int main() {
    int n = read(), m = read(), k = read(), t = read();
    int ans = -114514;
    while (k--) {
        int x = read(), y = read();
        int res = 0;
        for (int i = std :: max(1, x - t); i <= std :: min(n, x + t); ++i)
            for (int j = std :: max(1, y - t); j <= std :: min(m, y + t); ++j)
                if (dis(x, y, i, j) <= t)
                    ++res;
        ans = std :: max(ans, res);
    }
    printf("%d\n", ans);
    return 0;
}