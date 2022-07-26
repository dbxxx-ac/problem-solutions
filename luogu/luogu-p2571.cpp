/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-18 12:33:35 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-18 13:14:27
 */
#include <bits/stdc++.h>

double ax, ay, bx, by, cx, cy, dx, dy, p, q, r;
const double eps = 1e-8;

inline double dis(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double cal2(double ex, double ey, double fx, double fy) {
    return dis(ex, ey, fx, fy) / r + dis(fx, fy, dx, dy) / q;
}

double get(double ex, double ey) {
    double lx = cx, ly = cy, rx = dx, ry = dy;
    while (dis(lx, ly, rx, ry) > eps) {
        double x3 = (rx - lx) / 3;
        double y3 = (ry - ly) / 3;
        double lmidx = lx + x3, lmidy = ly + y3, rmidx = rx - x3, rmidy = ry - y3;
        if (cal2(ex, ey, rmidx, rmidy) - cal2(ex, ey, lmidx, lmidy) > eps) {
            rx = rmidx;
            ry = rmidy;
        } else {
            lx = lmidx;
            ly = lmidy;
        }
    }
    return cal2(ex, ey, rx, ry);
}

double cal(double ex, double ey) {
    return dis(ax, ay, ex, ey) / p + get(ex, ey);
}

int main() {
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy, &p, &q, &r);
    double lx = ax, ly = ay, rx = bx, ry = by;
    while (dis(lx, ly, rx, ry) > eps) {
        double x3 = (rx - lx) / 3, y3 = (ry - ly) / 3;
        double lmidx = lx + x3, lmidy = ly + y3, rmidx = rx - x3, rmidy = ry - y3;
        if (cal(rmidx, rmidy) - cal(lmidx, lmidy) > eps) {
            rx = rmidx;
            ry = rmidy;
        } else {
            lx = lmidx;
            ly = lmidy;
        }
    }
    printf("%.2lf\n", cal(rx, ry));
    return 0;
}