/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-04-02 02:12:38 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-04-02 02:19:13
 */
#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <algorithm>

const int maxn = 50005;

struct node {
    int x, y, z;
    bool operator < (const node &b) const {
        return this -> z < b.z;
    }
}a[maxn];

double getdis(int x1, int y1, int z1, int x2, int y2, int z2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
}

int main() {
    int n;
    std :: cin >> n;
    for(int i = 1; i <= n; i++)
        std :: cin >> a[i].x >> a[i].y >> a[i].z;
    std :: sort(a + 1, a + 1 + n);
    double ans;
    for(int i = 1; i < n; i++)
        ans += getdis(a[i].x, a[i].y, a[i].z, a[i + 1].x, a[i + 1].y, a[i + 1].z);
    std :: cout << std :: fixed << std :: setprecision(3) << ans << std :: endl;
    return 0;
}