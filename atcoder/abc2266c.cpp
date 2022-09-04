/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-08-27 20:23:40 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-08-27 20:43:51
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

int main() {
    int x1 = read(), y1 = read(), x2 = read(), y2 = read();
    int x3 = read(), y3 = read(), x4 = read(), y4 = read();
    printf("%d %d %d %d ", 
        (x2 - x1) * (y4 - y1) - (x4 - x1) * (y2 - y1),
        (x4 - x1) * (y3 - y1) - (x3 - x1) * (y4 - y1),
        (x4 - x2) * (y3 - y2) - (x3 - x2) * (y4 - y2),
        (x3 - x2) * (y1 - y2) - (x1 - x2) * (y3 - y2)
    );
    puts(
        ((((x2 - x1) * (y4 - y1) - (x4 - x1) * (y2 - y1)) * 
        ((x4 - x1) * (y3 - y1) - (x3 - x1) * (y4 - y1)) > 0) &&
        (((x4 - x2) * (y3 - y2) - (x3 - x2) * (y4 - y2)) * 
        ((x3 - x2) * (y1 - y2) - (x1 - x2) * (y3 - y2)) > 0)) ?
        "Yes" : "No"
    );
}