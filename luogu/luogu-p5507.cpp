/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-11-05 19:23:13 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-11-21 16:39:13
 */
#include <bits/stdc++.h>

const int maxn = 15;
const int maxm = 5;
const int n = 12;
const int m = 4;
const int bin = 1 << 24;
const int maxstep = 25;

inline int read() {
    int x = 0;
    bool f = true;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = false;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if (f) return x;
    return ~(x - 1);
}

int dir[bin];
int link[maxn][maxm];
int fa[bin], op[bin], v[bin];
int ans[maxstep];

std :: queue <int> q;

inline int get(int state, int x) {
    return (state >> (x << 1)) & 3;
}

int main() {
    int start = 0;
    for (int i = 0; i < n; ++i) {
        int x = read();
        start |= (x - 1) << (i << 1);
        for (int j = 0; j < m; ++j)
            link[i][j] = read() - 1;
    }

    int now = start;
    dir[now] = 1;
    dir[0] = -1;
    q.push(now);
    q.push(0);

    bool flag = false;
    int seq, inv, mid;
    while (!q.empty() && !flag) {
        int now = q.front(), curdir = dir[now];
        q.pop();
        for (int i = 0; i < n; ++i) {
            int nxt;
            int sti = get(now, i);
            int k = curdir == 1 ? 1 : 3;
            int link_num = link[i][curdir == 1 ? sti : ((sti + 3) & 3)];
            int stnxt = get(now, link_num);
            nxt = now ^ (sti << (i << 1)) ^ (((sti + k) & 3) << (i << 1));
            nxt ^= (stnxt << (link_num << 1)) ^ (((stnxt + k) & 3) << (link_num << 1));

            if (dir[nxt] == curdir)
                continue;
            if (dir[nxt]) {
                seq = curdir == 1 ? now : nxt;
                inv = curdir == 1 ? nxt : now;
                mid = i + 1;
                flag = true;
                break;
            }

            dir[nxt] = curdir;
            op[nxt] = i + 1;
            fa[nxt] = now;
            q.push(nxt);
        }
    }

    int seqcnt = 0, invcnt = 0;
    for (int now = seq; now != start; now = fa[now], ++seqcnt);
    for (int now = inv; now != 0; now = fa[now], ++invcnt);
    
    for (int i = 1, now = seq; now != start; ++i, now = fa[now])
        ans[seqcnt - i + 1] = op[now];
    ans[seqcnt + 1] = mid;
    for (int i = 1, now = inv; now != 0; ++i, now = fa[now])
        ans[seqcnt + i + 1] = op[now];
    
    std :: printf("%d\n", seqcnt + invcnt + 1);
    for (int i = 1; i <= seqcnt + invcnt + 1; ++i)
        std :: printf("%d ", ans[i]);
    puts("");
    
    return 0;
}