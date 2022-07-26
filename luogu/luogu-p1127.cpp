/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-09-26 13:17:28 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-09-26 20:02:32
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

const int maxn = 1005;
const int maxl = 30;

struct node {
    int v, id;
    std :: string word;
};

std :: vector <node> G[maxl];
int ind[maxl], outd[maxl];
bool letter[maxl], vis[maxn];

int n;
std :: string str[maxn], ans[maxn];

int cti(char c) {
    return c - 'a' + 1;
}

void GG() {
    puts("***");
    exit(0);
}

struct ufs {
    int fa[10086];
    bool valid[10086];
    int siz;

    void init(int n) {
        siz = n;
        for (int i = 1; i <= n; ++i)
            fa[i] = i;
    }

    int find(int x) {
        while (x != fa[x]) x = fa[x] = fa[fa[x]];
        return x;
    }
    
    void unite(int x, int y) {
        fa[find(x)] = find(y);
    }

    bool judge(int x, int y) {
        return find(x) == find(y);
    }

    int get_setnum() {
        int setnum = 0;
        for (int i = 1; i <= siz; ++i)
            if (fa[i] == i && valid[i])
                ++setnum;
        return setnum;
    }
};

void dfs(int u, int step) {
    if (step == n) {
        std :: printf("%s", ans[1].c_str());
        for (int i = 2; i <= n; ++i)
            std :: printf(".%s", ans[i].c_str());
        exit(0);
    }

    for (int i = 0; i < G[u].size(); ++i) {
        node e = G[u][i];
        if (!vis[e.id]) {
            vis[e.id] = true;
            ans[step + 1] = e.word;
            dfs(e.v, step + 1);
            vis[e.id] = false;
        }
    }

    return ;
}

int main() {
    std :: scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        std :: cin >> str[i];
    std :: sort(str + 1, str + 1 + n);

    ufs Gu;
    Gu.init(maxl);

    for (int i = 1; i <= n; ++i) {
        int first = cti(str[i][0]);
        int last = cti(str[i][str[i].length() - 1]);
        ++ind[last];
        ++outd[first];
        
        Gu.valid[last] = true;
        Gu.valid[first] = true;
        if (first != last) {
            if (!Gu.judge(first, last))
                Gu.unite(first, last);
        }

        G[first].push_back((node){last, i, str[i]});
    }

    if (Gu.get_setnum() != 1)
        GG();

    for (int i = 1; i <= 26; ++i)
        letter[i] = Gu.valid[i];

    //puts("Ok");

    int S = 0, E = 0;
    for (int i = 1; i <= 26; ++i) {
        if (!letter[i]) continue;
        if (outd[i] == ind[i] + 1) {
            if (S)
                GG();
            S = i;
        } else if (ind[i] == outd[i] + 1) {
            if (E)
                GG();
            E = i;
        } else if (ind[i] == outd[i]) {
            continue;
        } else {
            GG();
        }
    }

    if ((S && !E) || (!S && E))
        GG();
    
    if (!S) S = cti(str[1][0]);
    
    dfs(S, 0);
    
    return 0;
}