/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-11-02 22:43:05 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-11-02 23:09:32
 */
#include <iostream>
#include <cstdio>
#include <string>

const int ldays[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int ndays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isleap(int y) {
    if (y % 400 == 0)
        return true;
    if (y % 100 == 0)
        return false;
    if (y  % 4 == 0)
        return true;
    return false;
}

bool valid(int y, int m, int d) {
    if (m <= 0 || m >= 13)
        return false;
    if (isleap(y)) {
        if (d <= 0 || d > ldays[m])
            return false;
        return true;
    } else {
        if (d <= 0 || d > ndays[m])
            return false;
        return true;
    }
}

int check(int y1, int m1, int d1, int y2, int m2, int d2) {
    if (y1 > y2) return 1;
    if (y1 < y2) return -1;
    if (m1 > m2) return 1;
    if (m1 < m2) return -1;
    if (d1 > d2) return 1;
    if (d1 < d2) return -1;
    return 0;
}

int main() {
    int s1, s2;
    std :: scanf("%d %d", &s1, &s2);
    int y1 = s1 / 10000, y2 = s2 / 10000, ans = 0;
    int m1 = s1 % 10000 / 100, d1 = s1 % 100;
    int m2 = s2 % 10000 / 100, d2 = s2 % 100;

    for (int i = y1; i <= y2; ++i) {
        int m = i % 10 * 10 + i % 100 / 10;
        int d = i % 1000 / 100 * 10 + i / 1000;
        if (valid(i, m, d) && check(y1, m1, d1, i, m, d) <= 0 && check(y2, m2, d2, i, m, d) >= 0)
            ++ans;
    }
    std :: printf("%d\n", ans);
    return 0;
}