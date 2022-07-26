/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-30 21:30:35 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-30 21:49:17
 */
#include <iostream>
#include <cstdio>

const int maxn = 100005;
double a[maxn];
double min[maxn], sum[maxn], avg[maxn], maxscore;

int main() {
    int n;
    std :: scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        std :: scanf("%lf", &a[i]);
    
    for (int i = 2; i <= n + 1; ++i)
        min[i] = 10005;
    
    for (int i = n; i >= 2; --i) {
        min[i] = min[i + 1] < a[i] ? min[i + 1] : a[i];
        sum[i] = sum[i + 1] + a[i];
        if (i < n) {
            avg[i] = (sum[i] - min[i]) / (double)(n - i);
            maxscore = maxscore > avg[i] ? maxscore : avg[i];
        }
    }

    for (int i = 2; i <= n - 1; ++i)
        if (avg[i] == maxscore)
            std :: printf("%d\n", i - 1);
    return 0;
}