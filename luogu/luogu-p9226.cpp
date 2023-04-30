/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-22 14:34:32 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-22 18:44:32
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
    int n = read(), k = read();
    printf("%d\n", k - n % k);
    return 0;
}