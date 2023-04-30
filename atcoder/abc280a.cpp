/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-12-03 20:03:43 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-12-03 20:04:31
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
inline std :: pair <std :: string, int> rest(bool space = true) {
    std :: string s;
    char ch = getchar();
    for (; !isgraph(ch); ch = getchar());
    for (; isgraph(ch); ch = getchar())
        s.push_back(ch);
    return {space ? " " + s : s, s.length()};
}

int main() {
    int n = read(), m = read();
    int ans = 0;
    while (n--) {
        std :: string s = rest().first;
        for (int i = 1; i <= m; ++i)
            if (s[i] == '#')
                ++ans;
    }
    printf("%d\n", ans);
    return 0;
}