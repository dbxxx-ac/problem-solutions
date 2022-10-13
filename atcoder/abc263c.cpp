/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-03 15:14:07 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-03 15:21:03
 */
// 大家好，我是谢北宸，今天给大家表演一个 next_permutation 爆杀 dfs

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

const int maxm = 15;
int a[maxm];

int main() {
    int n = read(), m = read();
    
    for (int i = 1; i <= m; ++i)
        a[i] = (i > n);
    
    do {
        for (int i = 1; i <= m; ++i)
            if (a[i] == 0)
                printf("%d ", i);
        puts("");
    } while (std :: next_permutation(a + 1, a + 1 + m));

    return 0;
}