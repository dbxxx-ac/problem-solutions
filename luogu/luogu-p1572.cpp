/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-03 18:39:26 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-03 20:06:19
 */
#include <iostream>
#include <cstdio>

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int sum = 0;
    int a, b, la, lb, son, mom;
    std :: scanf("%d/%d", &la, &lb);
    while (~std :: scanf("%d/%d", &a, &b)) {
        int g = gcd(lb, b);
        int l = lb * b / g;
        mom = l;
        son = la * (l / lb) + a * (l / b);
        la = son / gcd(son, mom);
        lb = mom / gcd(son, mom);
    }
    
    son = la;
    mom = lb;

    if (mom < 0) {
        son = -son;
        mom = -mom;
    }

    if (son % mom == 0)
        std :: printf("%d\n", son / mom);
    else
        std :: printf("%d/%d\n", son, mom);
    return 0;
}