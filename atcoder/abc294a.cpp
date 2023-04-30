/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-19 20:00:20 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-19 20:00:59
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
    int n = read();
    for (int i = 1; i <= n; ++i) {
        int x = read();
        if (x % 2 == 0)
            printf("%d ", x);
    }
    puts("");
    return 0;
}