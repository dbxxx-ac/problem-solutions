/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-11-13 03:03:58 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-11-13 03:29:05
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
inline char rech() {
    char ch = getchar();
    while (!isalpha(ch))
        ch = getchar();
    return ch;
}
inline std :: string rest() {
    std :: string s;
    char ch = getchar();
    for (; !isgraph(ch); ch = getchar());
    for (; isgraph(ch); ch = getchar())
        s.push_back(ch);
    return s;
}

const int maxb = (int)1e6 + 5;
const int maxt = 1005;

int p[maxb];
std :: queue <int> q[maxt];

int main() {
    for (int cas = 1, t = read(); t; t = read(), ++cas) {
        printf("Scenario #%d\n", cas);
        for (int i = 1; i <= t; ++i) {
            int cnt = read();
            while (cnt--) {
                int id = read();
                p[id] = i;
            }
        }

        for (std :: string st = rest(); st[0] != 'S'; st = rest()) {
            if (st[0] == 'E') {
                int id = read(), x = p[id];
                if (q[x].empty())
                    q[0].push(x);
                q[x].push(id);
            } else if (st[0] == 'D') {
                int x = q[0].front();
                int id = q[x].front();
                printf("%d\n", id);
                q[x].pop();
                if (q[x].empty())
                    q[0].pop();
            }
        }

        for (int i = 0; i <= t; ++i)
            while (!q[i].empty())
                q[i].pop();
            
        puts("");
    }

    return 0;
}