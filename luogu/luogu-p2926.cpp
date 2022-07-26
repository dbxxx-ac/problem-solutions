/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-02 12:18:11 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-02 12:22:16
 */
#include <iostream>
#include <cstdio>

const int maxn = 100005;
const int maxnum = 1000005;

int bucket[maxnum], cnt[maxnum];
int a[maxn];

int main() {
    int n;
    std :: scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        std :: scanf("%d", &a[i]);
        ++bucket[a[i]];
    }

    for (int i = 1; i < maxnum; ++i) {
        if (bucket[i]) {
            for (int j = 1; j <= maxnum / i; ++j) {
                if (bucket[i * j]) cnt[i * j] += bucket[i];
                if (j == 1) --cnt[i];
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        std :: printf("%d\n", cnt[a[i]]);
    return 0;
}