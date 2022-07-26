/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-03-12 01:24:35 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-03-13 01:27:42
 */
#include <iostream>
#include <cstdio>

const int maxm = 105;
const int maxt = 1005;

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
        for(int j = T; j >= v[i]; j--)
            dp[j] = max(dp[j],dp[j - v[i]] + w[i]);
        
    std :: cout << dp[T] << std :: endl;
    return 0;
}