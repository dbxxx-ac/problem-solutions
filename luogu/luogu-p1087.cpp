/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-26 08:40:37 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-26 08:43:52
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

const int maxn = (1 << 10) + 5;
char s[maxn];

void dfs(int l, int r) {
    if (l != r) {
        int mid = l + r >> 1;
        dfs(l, mid);
        dfs(mid + 1, r);
    }
    for (int i = l; i < r; ++i)
        if (s[i] != s[i + 1]) {
            putchar('F');
            return ;
        }
    if (s[l] == '1')
        putchar('I');
    else
        putchar('B');
    return ;
}

int main() {
    int n = read();
    scanf("%s", s + 1);
    dfs(1, (1 << n));
    return 0;
}