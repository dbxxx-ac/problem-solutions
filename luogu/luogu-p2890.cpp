/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-09-04 12:24:18 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-09-04 12:44:24
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

const int maxn = 2005;
const int maxb = 29;

char s[maxn];
int v[maxb];
int f[maxn][maxn];

inline int min(int a, int b) {
    return a < b ? a : b;
}

inline bool chkmin(int &a, int b) {
    return b < a ? a = b, true : false;
}

int main() {
    int m = read(), n = read(); // 含义与题面相反
    scanf("%s", s + 1);

    for (int i = 1; i <= m; ++i) {
        char ch;
        std :: cin >> ch;
        int va1 = read(), va2 = read();
        // printf("%c %d %d\n", ch, va1, va2);
        v[ch - 'a'] = min(va1, va2);
    }
    
    for (int len = 1; len <= n; ++len) {
        for (int l = 1, r = len; r <= n; ++l, ++r) {
            f[l][r] = min(f[l + 1][r] + v[s[l] - 'a'], f[l][r - 1] + v[s[r] - 'a']);
            if (s[l] == s[r])
                chkmin(f[l][r], f[l + 1][r - 1]);
        }
    }

    printf("%d\n", f[1][n]);
    return 0;
}