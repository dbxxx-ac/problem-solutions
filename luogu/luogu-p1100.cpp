/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-01 12:28:31 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-01 12:29:37
 */
#include <iostream>
#include <cstdio>

int main() {
    unsigned int x;
    std :: scanf("%u", &x);
    std :: printf("%u\n", (x >> 16) | (x << 16));
    return 0;
}