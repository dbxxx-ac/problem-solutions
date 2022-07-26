/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-06-16 09:18:57 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-06-16 15:27:24
 */
/*二分法
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>

const double eps = 1e-10;

double n, m, k;
bool check(double x) {
    return pow(1.0 / (1.0 + x), k) >= 1 - n / m * x;
}

int main() {
    std :: cin >> n >> m >> k;
    double l = 0, r = 10086;
    while (r - l >= eps) {
        double mid = (l + r) / 2;//不能用位运算了啊啊啊啊啊啊啊啊暴风哭泣
        if (check(mid)) r = mid;
        else l = mid;
    }

    std :: cout << std :: fixed << std :: setprecision(1) << l * 100 << std :: endl;
    return 0;
}
*/
//倍增
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>

const double eps = 1e-10;
double n, m, k;

bool check(double x) {
    return pow(1.0 / (1.0 + x), k) >= 1 - n / m * x;
}

int main() {
    std :: cin >> n >> m >> k;
    double ans = 0;
    double add = 0.1;
    while (add >= eps) {
        if (!check(ans + add)) {
            ans += add;
            add *= 2.0;
        }
        else
            add /= 2.0;
    }

    std :: cout << std :: fixed << std :: setprecision(1) << ans * 100 << std :: endl;
    return 0;
}
