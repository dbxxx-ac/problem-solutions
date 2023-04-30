/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-01-14 20:14:29 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-01-14 20:16:47
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

int main() {
    std :: string s = std :: to_string(read() + 99999);
    std :: vector <int> v = {0, 0, 1, 2, 3, 3, 4, 5, 4};
    for (int x : v)
        putchar(s[x]);
    puts("");
    return 0;
}