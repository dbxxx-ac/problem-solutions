/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-24 12:29:41 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-24 12:40:16
 */
#include <iostream>
#include <cstdio>
#include <climits>
#include <cstring>

const int maxn = 10005;

bool a[maxn], sum[maxn];

int main() {
    int n;
    std :: scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        char dir;
        std :: cin >> dir;
        a[i] = (dir == 'F');
    }

    int m = INT_MAX / 4, k;
    
    for (int l = 1; l <= n; ++l) {
        std :: memset(sum, false, sizeof(sum));
        bool b = false;
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            b ^= sum[i];
            if ((!a[i] ^ b)) {
                if (i + l - 1 > n) {
                    cnt = INT_MAX / 4;
                    break;
                }
                b ^= 1;
                sum[i + l] ^= 1;
                ++cnt;
            }
        }

        if (cnt < m) {
            m = cnt;
            k = l;
        }
    }

    std :: printf("%d %d\n", k, m);
    return 0;
}