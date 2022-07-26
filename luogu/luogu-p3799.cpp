/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-04-06 00:25:54 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-04-06 09:49:08
 */
#include <iostream>
#include <cstdio>
#include <climits>

typedef long long ll;
const int mod = 1e9 + 7;
const int maxl = 5e3 + 5;

int a[maxl];

inline int max(int a, int b) {
    return a > b ? a : b;
}

inline int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n;
    ll ans = 0;
    std :: cin >> n;
    
    int begin = INT_MAX;
    int end = INT_MIN;

    for(int i = 1; i <= n; i++) {
        int len;
        std :: cin >> len;
        begin = min(begin, len);
        end = max(end, len);
        a[len]++;
    }

    for(int i = begin + 1; i <= end; i++) {
        if(a[i] > 1) {
            for(int j = begin; j <= i / 2; j++) {
                if(a[j] && a[i - j]) {
                    if(j == i - j && a[j] >= 2)
                        ans = ans + ((a[i] * (a[i] - 1) >> 1) * (a[j] * (a[j] - 1) >> 1) % mod) % mod;
                    else if(j != i - j)
                        ans = ans + ((a[i] * (a[i] - 1) >> 1) * a[j] * a[i - j]) % mod;      
                }
                ans %= mod;
            }
        }
    }

    std :: cout << ans << std :: endl;
    return 0;
}