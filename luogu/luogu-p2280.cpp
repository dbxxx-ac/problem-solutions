/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-29 11:44:02 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-29 11:52:11
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

const int maxv = (int)5e3 + 5;
const int v = (int)5e3 + 1;

int s[maxv][maxv];

int main() {
    int n = read(), m = read();
    while (n--) {
        int x = read(), y = read(), v = read();
        s[x + 1][y + 1] += v;
    }

    for (int i = 1; i <= v; ++i)
        for (int j = 1; j <= v; ++j)
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    
    int ans = 0;
    for (int i = m; i <= v; ++i)
        for (int j = m; j <= v; ++j)
            gmx(ans, s[i][j] - s[i - m][j] - s[i][j - m] + s[i - m][j - m]);
    
    printf("%d\n", ans);
    return 0;
}