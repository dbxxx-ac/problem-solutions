/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-03-17 14:17:46 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-03-17 14:20:37
 */
#include <iostream>
#include <cstdio>

int main() {
    double n;
    std :: cin >> n;
    std :: printf("%.12f", n * (n + 1) / (2 * (2 * n - 1)));
    return 0;
}