/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-17 18:02:41 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-17 20:33:14
 */
#include <bits/stdc++.h>
const int maxn = 15;
const double eps = 1e-5;

double a[maxn];
int n;
double l, r;

double cal(double x) {
    double ans = 0;
    for (int i = n; i >= 0; --i)
        ans = ans * x + a[i];
    return ans;
}

int main() {
    scanf("%d %lf %lf", &n, &l, &r);

    for (int i = n; i >= 0; --i)
        scanf("%lf", &a[i]);
    
    while (std :: fabs(r - l) >= eps) {
        double mid = (l + r) / 2.0;
        if (cal(mid - eps) < cal(mid + eps))
            l = mid;
        else
            r = mid;
    }

    printf("%.5lf\n", r);
    return 0;
}