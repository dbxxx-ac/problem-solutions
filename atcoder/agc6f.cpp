/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-25 02:05:23 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-25 03:15:21
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

const int maxm = (int)2e5 + 5; // 注意双倍建图要双倍数组大小
const int maxn = (int)1e5 + 5;

struct edge {
    int to, nxt, w;
}e[maxm];

int head[maxn], ecnt = 0;
inline void add_edge(int u, int v, int w) {
    e[++ecnt].to = v;
    e[ecnt].w = w;
    e[ecnt].nxt = head[u];
    head[u] = ecnt;
}

int c[maxn], cnt[5];
// c 数组代表第 i 个节点的颜色，注意程序中为了方便，染色使用0, 1, 2
// cnt 数组代表第 i 个颜色的节点数量，统计用

inline int cal(int u, int w) {
    return (u + w) % 3; // 计算节点 u 的后 w 个颜色
}

std :: queue <int> q;

int main() {
    std :: memset(c, -1, sizeof(c)); // -1 才表示未染色，因为 0 是颜色之一
    int n = read(), m = read(); // m 是题目中的 n，n 是题目中的 m
    while (m--) {
        int x = read(), y = read();
        add_edge(x, y, 1);
        add_edge(y, x, 2); // 在 %3 意义下相当于 -1，但是不用判断负数
        // n = std :: max(n, std :: max(x, y)); // n 取最大的 x, y
    }

    long long ans = m = 0; // m 已经没有用了，这里我们用它来维护每个弱联通块的边数
    bool flag = false; // 染色是否矛盾
    for (int i = 1; i <= n; ++i) {
        if (c[i] != -1) // 如果不是新弱联通块就 continue
            continue;
        // 接下来都是从新的弱联通块中一个点开始 bfs
        cnt[0] = cnt[1] = cnt[2] = c[i] = m = 0;
        flag = false;
        q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ++cnt[c[u]]; // 统计 cnt
            for (int j = head[u]; j; j = e[j].nxt) {
                ++m; // 统计边
                int v = e[j].to;
                if (c[v] != -1) { // 已经染色
                    if (c[v] != cal(c[u], e[j].w)) // 矛盾
                    // 当前需要给他染的色和之前给他染的色不匹配
                        flag = true;
                } else { // 未染色
                    c[v] = cal(c[u], e[j].w); // 染色
                    q.push(v);
                }
            }
        }
        if (flag) // 情况三
            ans += 1LL * (cnt[0] + cnt[1] + cnt[2]) * (cnt[0] + cnt[1] + cnt[2]);
            // 明显地 cnt[0] + cnt[1] + cnt[2] 代表总共点数
        else if ((cnt[0] != 0) && (cnt[1] != 0) && (cnt[2] != 0)) // 情况一
            ans += 1LL * cnt[0] * cnt[1] + 1LL * cnt[1] * cnt[2] + 1LL * cnt[0] * cnt[2];
        else // 情况二
            ans += m >> 1; // 因为双倍建图所以实际边数应该是双倍的图中的边数除以2
    }
    printf("%lld\n", ans);
    return 0;
}