/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-03-11 23:42:13 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-03-12 00:19:27
 */
#include <iostream>
#include <cstdio>

const int maxn = 32005;
inline int max(int a, int b) {
    return a > b ? a : b;
}

int n,m;

struct MAIN {
    int v,w;
}my_main[maxn];

struct ANNEX {
    int v[3],w[3],cnt = 0;
}my_annex[maxn];

int dp[maxn];

int main() {
    std :: cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int tmpv,tmpp,tmpq;
        std :: cin >> tmpv >> tmpp >> tmpq;
        if(tmpq) {
            my_annex[tmpq].cnt++;
            my_annex[tmpq].v[my_annex[tmpq].cnt] = tmpv;
            my_annex[tmpq].w[my_annex[tmpq].cnt] = tmpv * tmpp;
        }
        else {
            my_main[i].v = tmpv;
            my_main[i].w = tmpv * tmpp;
        }
    }

    for(int i = 1; i <= m; i++)
        for(int j = n; j >= my_main[i].v; j--) {
            dp[j] = max(dp[j], dp[j - my_main[i].v] + my_main[i].w);
            if(j >= my_main[i].v + my_annex[i].v[1]) dp[j] = max(dp[j], dp[j - my_main[i].v - my_annex[i].v[1]] + my_main[i].w + my_annex[i].w[1]);
            if(j >= my_main[i].v + my_annex[i].v[2]) dp[j] = max(dp[j], dp[j - my_main[i].v - my_annex[i].v[2]] + my_main[i].w + my_annex[i].w[2]);
            if(j >= my_main[i].v + my_annex[i].v[1] + my_annex[i].v[2]) dp[j] = max(dp[j], dp[j - my_main[i].v - my_annex[i].v[1] - my_annex[i].v[2]] + my_main[i].w + my_annex[i].w[1] + my_annex[i].w[2]);
        }

    std :: cout << dp[n] << std :: endl;
    return 0;
}