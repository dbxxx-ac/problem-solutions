/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-09-04 12:11:50 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-09-04 12:21:38
 */
#include <bits/stdc++.h>

const int maxn = 1005;
char s[maxn];
int f[maxn][maxn];

inline bool chkmin(int &a, int b) {
    return b < a ? a = b, true: false;
}

inline int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    
    for (int len = 2; len <= n; ++len) {
        for (int l = 1, r = len; r <= n; ++l, ++r) {
            f[l][r] = min(f[l + 1][r], f[l][r - 1]) + 1;
            if (s[l] == s[r])
                chkmin(f[l][r], f[l + 1][r - 1]);
        }
    }

    printf("%d\n", f[1][n]);
    return 0;
}