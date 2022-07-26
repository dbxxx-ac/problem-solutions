/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-06-20 10:23:34 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-06-20 11:24:03
 */
#include <iostream>
#include <cstdio>

int main() {
    int n;
    std :: cin >> n;
    for (int i = 1; i <= n; i++, puts(""))
        for (int j = 1; j <= n; j++)
            printf("%02d", i * n - n + j);
    
    puts("");

    for (int i = 1; i <= n; i++, puts(""))
        for (int j = 1; j <= n; j++)
            if (j <= n - i) printf("  ");
            else printf("%02d", i * (i + 1) / 2 - n + j);
    
    return 0;   
}