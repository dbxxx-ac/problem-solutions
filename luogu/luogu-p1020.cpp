/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-16 14:30:15 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-16 16:20:14
 */
#include <bits/stdc++.h>
inline int read() {
    int x = 0;
    bool flag = true;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            flag = false;
        if (ch == EOF)
            return 0;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if(flag)
        return x;
    return ~(x - 1);
}

const int maxn = 1e5 + 5;
int p[maxn], q[maxn];

int main() {
    int s = 1, t = 1;
    int x = read();
    p[1] = q[1] = x;
    for (x = read(); x; x = read()) {
        if (p[s] >= x)
            p[++s] = x;
        else
            *std :: upper_bound(p + 1, p + 1 + s, x, std :: greater <int> ()) = x;
        if (q[t] < x)
            q[++t] = x;
        else
            *std :: lower_bound(q + 1, q + 1 + t, x) = x;
    }
    printf("%d %d\n", s, t);
    return 0;
}

/*
389 207 155 300 299 170 158 65
4 1 8 7 3 5 2 6
6 8 2    
*/