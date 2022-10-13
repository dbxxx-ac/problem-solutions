/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-07 22:53:38 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-08 01:42:14
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

const int maxn = (int)1e5 + 5;
const int maxm = (int)1e5 + 5;
typedef std :: pair <int, int> pii;

std :: vector <pii> G[maxn];
std :: vector <int> ans;
std :: stack <int> vst, est;

int dfn[maxn], low[maxn], times;

inline bool gmi(int &a, int b) {
    return b < a ? a = b, true : false;
}

void tarjan(int u, int lst) {
    dfn[u] = low[u] = ++times;
    vst.push(u);

    for (pii e : G[u]) {
        int v = e.first, id = e.second;
        if (!dfn[v]) {
            int erz = est.size();
            est.push(id);
            tarjan(v, id);
            gmi(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                int ent = est.size() - erz, vnt = 1;
                while (!vst.empty()) {
                    int x = vst.top();
                    vst.pop();
                    ++vnt;
                    if (x == v)
                        break;
                }

                // printf("%d %d %d\n", low[u], low[v], ent);
                while (!est.empty()) {
                    int x = est.top();
                    est.pop();
                    if (ent == vnt)
                        ans.push_back(x);
                    if (x == id)
                        break;
                }
            }
        } else if (id != lst) {
            gmi(low[u], dfn[v]);
            est.push(id);
        }
    }
}

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        G[u].emplace_back(v, i);
        G[v].emplace_back(u, i);
    }

    for (int u = 1; u <= n; ++u)
        if (!dfn[u])
            tarjan(u, 0);
    
    printf("%d\n", (int)ans.size());
    std :: sort(ans.begin(), ans.end());
    
    for (auto x : ans)
        printf("%d ", x);
    puts("");
    return 0;
}