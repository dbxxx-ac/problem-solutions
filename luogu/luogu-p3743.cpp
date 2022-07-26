/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-06-20 12:02:51 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-06-20 14:55:20
 */
#include <iostream>
#include <cstdio>
#include <climits>
#include <iomanip>

const int maxn = 100005;
const double eps = 1e-6;

int n, p;
double a[maxn], b[maxn];
bool check(double x) {
    double need = 0;
    for (int i = 1; i <= n; ++i)
        if (b[i] < a[i] * x)
            need += a[i] * x - b[i];
    return need <= p * x;
}

int main() {
    std :: cin >> n >> p;
    for (int i = 1; i <= n; ++i)
        std :: cin >> a[i] >> b[i];
    
    double sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += a[i];
    if (sum <= p) {
        std :: cout << -1 << std :: endl;
        return 0;
    }

    double l = 0;
    double r = 3000000001;

    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }

    std :: cout << std :: fixed << std :: setprecision(8) << r << std :: endl; 
}