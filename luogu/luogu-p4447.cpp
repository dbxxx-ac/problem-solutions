/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-06-12 23:56:53 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-06-13 00:22:02
 */

#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>

#undef min

inline int min(int a, int b) {
    return a < b ? a : b;
}

inline int read() {
    int x;
    std :: cin >> x;
    return x;
}

const int maxn = 100005;

int a[maxn];
int team_max[maxn];
int team_num;
int team_size[maxn];
int ans = INT_MAX;

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    std :: sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        int chgidx = 0;
        int chgnum = INT_MAX;
        for (int j = 1; j <= team_num; ++j) {
            if (team_max[j] + 1 == a[i] && team_size[j] < chgnum) {
                chgidx = j;
                chgnum = team_size[j];
            }
        }

        if (chgnum == INT_MAX) {
            team_max[++team_num] = a[i];
            team_size[team_num] = 1;
        } else {
            team_max[chgidx] = a[i];
            ++team_size[chgidx];
        }
    }

    for (int i = 1; i <= team_num; i++) ans = min(ans, team_size[i]);
    printf("%d\n", ans);
    return 0;
}
