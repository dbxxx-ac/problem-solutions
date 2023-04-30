/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-11-18 16:10:43 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-11-18 16:15:39
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
inline bool gmx(int &a, int b) {
    return b > a ? a = b, true : false;
}

int f[35];

int main() {
    for (int n = read(); n; --n) {
        int x = read(), l = 0;
        for (int i = 0; i <= 30; ++i)
            if (x & (1 << i))
                gmx(l, f[i] + 1);
        for (int i = 0; i <= 30; ++i)
            if (x & (1 << i))
                f[i] = l;
    }

    printf("%d\n", *std :: max_element(f, f + 30));
    return 0;
}