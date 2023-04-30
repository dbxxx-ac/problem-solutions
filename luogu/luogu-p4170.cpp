/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-11-20 01:07:36 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-11-20 01:11:22
 */
#include <bits/stdc++.h>
inline std :: string rest() {
    std :: string s;
    char ch = getchar();
    for (; !isgraph(ch); ch = getchar());
    for (; isgraph(ch); ch = getchar())
        s.push_back(ch);
    return s;
}
inline bool gmi(int &a, int b) {
    return b < a ? a = b, true : false;
}

const int maxn = 55;

int f[maxn][maxn];

int main() {
    std :: string s = " " + rest();
    int n = s.length() - 1;

    for (int i = 1; i <= n; ++i)
        f[i][i] = 1;
    
    for (int len = 2; len <= n; ++len) {
        for (int l = 1, r = len; r <= n; ++l, ++r) {
            if (s[l] == s[r])
                f[l][r] = f[l][r - 1];
            else {
                f[l][r] = INT_MAX;
                for (int i = l; i < r; ++i)
                    gmi(f[l][r], f[l][i] + f[i + 1][r]);
            }
        }
    }

    printf("%d\n", f[1][n]);
    return 0;
}