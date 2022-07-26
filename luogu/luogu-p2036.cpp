/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-04-13 22:01:53 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-04-13 22:17:12
 */
#include <iostream>
#include <cstdio>
#include <climits>

inline int min(int a, int b) {
    return a < b ? a : b;
}

inline int abs(int x) {
    return x > 0 ? x : -x;
}

const int maxn = 15;
int n, ans = INT_MAX;
struct flavor {
    int s, b;
}a[maxn];

void dfs(int num, int nows, int nowb, bool chosen) {
    if(num > n) {
        if(!chosen) return ;
        ans = min(ans, abs(nows - nowb));
        return ;
    }
    dfs(num + 1, nows * a[num].s, nowb + a[num].b, true);
    dfs(num + 1, nows, nowb, chosen);
}

int main() {
    std :: cin >> n;
    for(int i = 1; i <= n; i++)
        std :: cin >> a[i].s >> a[i].b;
    dfs(1, 1, 0, false);    
    std :: cout << ans << std :: endl;
    return 0;
}