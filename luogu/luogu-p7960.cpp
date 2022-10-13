/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-09-04 22:59:23 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-09-04 23:30:34
 */
#include <bits/stdc++.h>
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

const int maxn = (int)1e7 + 5;

int ans[maxn];

inline bool hav7(int x) {
    while (x) {
        int p = x % 10;
        x /= 10;
        if (p == 7)
            return true;
    }
    return false;
}

int main() {
    for (int i = 1, lst = 0; i <= maxn - 4; ++i) {
        if (ans[i] == -1)
            continue;
        if (hav7(i)) {
            for (int j = i; j <= maxn - 4; j += i)
                ans[j] = -1;
            continue;
        }
        ans[lst] = i;
        lst = i;
    }

    int T = read();
    while (T--) {
        int x = read();
        printf("%d\n", ans[x]);
    }
    return 0;
}