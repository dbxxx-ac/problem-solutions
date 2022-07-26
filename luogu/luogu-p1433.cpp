/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-02-22 23:12:58 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-02-22 23:12:58  
 */
//插件出锅了……Last Modified time应该是2020-02-23 00:58分钟左右，不知道他咋想的，，
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#undef y1

int n;
const int maxn = 25;
double dp[25][40005];

struct cheese {
    double x;
    double y;
}a[maxn];

double getdis(double x1,double y1,double x2,double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double min(double a,double b) {
    return a < b ? a : b;
}

int main() {
    memset(dp,127,sizeof(dp));
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) scanf("%lf %lf",&a[i].x,&a[i].y);

    for(int s = 1; s <= (1 << n) - 1; s++) {
        for(int i = 1; i <= n; i++) {
            if(s & (1 << (i - 1))) {
                if(s == (1 << (i-1))) {
                        dp[i][s] = 0;
                        continue;
                }
                for(int j = 1; j <= n; j++) {
                    if(i != j && s & (1 << (j - 1))) {
                        dp[i][s] = min(dp[i][s],dp[j][s - (1 << (i - 1))] + getdis(a[i].x,a[i].y,a[j].x,a[j].y));
                    }
                }
            }
        }
    }

    double ans = 1008610086;
    for(int i = 1; i <= n; i++) ans = min(ans,dp[i][(1 << n) - 1]+getdis(a[i].x,a[i].y,a[0].x,a[0].y));
    printf("%.2lf\n",ans);
    return 0;
}