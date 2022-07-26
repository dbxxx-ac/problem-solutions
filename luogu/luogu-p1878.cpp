/*
 * @Author: crab-in-the-northeast 
 * @Date: 2021-02-19 10:46:59 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2021-02-19 10:48:31
 */
#include <bits/stdc++.h>
inline int read() {
    int x = 0;
    bool flag = true;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            flag = false;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if (flag)
        return x;
    return ~(x - 1);
}

inline int abs(int x) {
    return x > 0 ? x : -x;
}

const int maxn = 200005;

std :: vector <std :: pair <int, int> > ans;
bool vis[maxn];
int a[maxn];

struct node {
    int fst, lst, dif;
    bool operator < (const node &b) const {
        if (this -> dif == b.dif)
            return this -> fst > b.fst;
        return this -> dif > b.dif;
    }
};

std :: priority_queue <node> pq;

int main() {
    int n = read();
    std :: string gdr;
    std :: cin >> gdr;
    gdr = " " + gdr;

    for (int i = 1; i <= n; ++i)
        a[i] = read();
    
    for (int i = 1; i < n; ++i)
        if (gdr[i] != gdr[i + 1])
            pq.push((node){i, i + 1, abs(a[i + 1] - a[i])});
    
    while (!pq.empty()) {
        int fst = pq.top().fst;
        int lst = pq.top().lst;
        pq.pop();
        if (!vis[fst] && !vis[lst]) {
            vis[fst] = vis[lst] = true;
            ans.push_back(std :: make_pair(fst, lst));
            while (fst >= 1 && vis[fst])
                --fst;
            while (lst <= n && vis[lst])
                ++lst;
            if (fst >= 1 && lst <= n && gdr[fst] != gdr[lst])
                pq.push((node){fst, lst, abs(a[lst] - a[fst])});
        }
    }

    std :: printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        std :: printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}