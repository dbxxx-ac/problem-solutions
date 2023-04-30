/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-24 08:57:32 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-24 08:58:22
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
    
}