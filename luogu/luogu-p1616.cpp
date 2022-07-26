/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-03-12 20:54:13 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-03-13 01:28:22
 */
#include <iostream>
#include <cstdio>

const int maxm = 10005;
const int maxt = 100005;

inline int max(int a,int b) {
    return a > b ? a : b;
}

int v[maxm],w[maxm],dp[maxt];

int main() {
    int T,M;
    std :: cin >> T >> M;
    for(int i = 1; i <= M; i++) 
        std :: cin >> v[i] >> w[i];
    
    for(int i = 1; i <= M; i++)
        for(int j = v[i]; j <= T; j++)
            dp[j] = max(dp[j],dp[j - v[i]] + w[i]);
        
    std :: cout << dp[T] << std :: endl;
    return 0;
}