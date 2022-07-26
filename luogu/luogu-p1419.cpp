/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-24 12:00:53 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-24 12:14:51
 */
#include <iostream>
#include <cstdio>
#include <deque>

const int maxn = 100005;
const int maxinf = 10000;
const int mininf = -maxinf;
const double eps = 1e-5;

int a[maxn];
int n;
int s, t;
double sum[maxn];

bool check(double x) {
    std :: deque <int> q;
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + ((double)a[i] - x);
    
    for (int i = 1; i <= n; ++i) {
        if (i >= s) {
            while (!q.empty() && sum[i - s] < sum[q.back()])
                q.pop_back();
            q.push_back(i - s);
        }

        if (!q.empty() && q.front() < i - t)
            q.pop_front();
        if (!q.empty() && sum[i] - sum[q.front()] >= 0)
            return true;
    }

    return false;
}

int main() {
    std :: scanf("%d", &n);
    std :: scanf("%d %d", &s, &t);
    for (int i = 1; i <= n; ++i)
        std :: scanf("%d", &a[i]);
    
    double l = mininf, r = maxinf;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }

    std :: printf("%.3lf\n", l);
    return 0;
}