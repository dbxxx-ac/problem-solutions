/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-12-03 20:13:02 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-12-03 20:14:42
 */
#include <bits/stdc++.h>
inline std :: pair <std :: string, int> rest(bool space = true) {
    std :: string s;
    char ch = getchar();
    for (; !isgraph(ch); ch = getchar());
    for (; isgraph(ch); ch = getchar())
        s.push_back(ch);
    return {space ? " " + s : s, s.length()};
}

int main() {
    auto [s, n] = rest(); std :: string t = rest().first;
    for (int i = 1; i <= n; ++i) {
        if (s[i] != t[i]) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("%d\n", n + 1);
    return 0;
}