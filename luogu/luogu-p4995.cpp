/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-05-05 22:31:09 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-05-05 22:44:00
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

const int maxn = 305;
int n;
int nowh;
long long ans;
int h[maxn];

int main() {
    std :: cin >> n;
    for(int i = 1; i <= n; i++)
        std :: cin >> h[i];
    std :: sort(h + 1, h + n + 1);
    for(int i = 1; i <= (n >> 1); i++) {
        ans += (h[n - i + 1] - nowh) * (h[n - i + 1] - nowh);
        nowh = h[n - i + 1];
        ans += (nowh - h[i]) * (nowh - h[i]);
        nowh = h[i];
    }
    if(n & 1) ans += (h[(n >> 1) + 1] - nowh) * (h[(n >> 1) + 1] - nowh);
    std :: cout << ans << std :: endl;
    return 0;
}