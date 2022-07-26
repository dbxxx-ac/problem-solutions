/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-05-02 23:29:11 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-05-02 23:33:26
 */
#include <iostream>
#include <cstdio>

const int maxn = 1e5 + 5;

int a[maxn];

int main() {
    int n, x;
    long long ans = 0;
    std :: cin >> n >> x;
    for(int i = 1; i <= n; i++)
        std :: cin >> a[i];
    if(a[1] > x) {
        ans += a[1] - x;
        a[1] = x;
    }
    for(int i = 2; i <= n; i++) {
        if(a[i] + a[i - 1] > x) {
            ans += a[i] + a[i - 1] - x;
            a[i] = x - a[i - 1];
        }
    }
    std :: cout << ans << std :: endl;
    return 0;
}