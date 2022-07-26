/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-09-30 19:35:47 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-09-30 20:43:22
 */
#include <iostream>
#include <cstdio>
#include <climits>
#include <vector>
#include <queue>

const int maxn = CHAR_MAX;
const int maxm = 605;

std :: vector <int> G[maxn];
int ind[maxn];

int n, m;

int c_to_i(char ch) {
    return ch - 'A' + 1;
}

std :: queue <int> seq;

int topsort() {
    std :: queue <int> q;
    bool valid = true;
    for (int i = 1; i <= n; ++i)
        if (ind[i] == 0) {
            q.push(i);
            seq.push(i);
        }
    
    if (q.size() > 1)
        valid = false;

    
    while (!q.empty()) {
        bool flag = false;
        int u = q.front();
        q.pop();
        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i];
            --ind[v];
            if (ind[v] == 0) {
                if (flag) valid = false;
                q.push(v);
                seq.push(v);
                flag = true;
            }
        }
    }

    if (seq.size() != n) return -1;
    if (!valid) return 0;
    return 1;
}

int main() {
    std :: scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        char str[5];
        std :: scanf("%s", str + 1);
        int u = c_to_i(str[1]), v = c_to_i(str[3]);
        G[u].push_back(v);
        for (int j = 1; j <= n; ++j)
            ind[j] = 0;
        for (int u = 1; u <= n; ++u)
            for (int j = 0; j < G[u].size(); ++j)
                ++ind[G[u][j]];
        
        while (!seq.empty())
            seq.pop();
        
        int res = topsort();
        if (res == 1) {
            std :: printf("Sorted sequence determined after %d relations: ", i);
            while (!seq.empty()) {
                std :: printf("%c", seq.front() + 'A' - 1);
                seq.pop();
            }
            puts(".");
            return 0;
        } else if (res == -1) {
            std :: printf("Inconsistency found after %d relations.\n", i);
            return 0;
        }
    }

    puts("Sorted sequence cannot be determined.");
    return 0;
}