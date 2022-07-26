/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-02-26 02:34:12 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-02-26 02:39:44
 */
#include <iostream>
#include <cstdio>

int main() {
    int m;
    scanf("%d",&m);
    for(int i = 1; i <= m / 2; i++) {
        int sum = 0;
        int j;
        for(j = i; j < m && sum < m; j++) sum += j;
        if(sum == m) printf("%d %d\n",i,j - 1);
    }
    return 0;
}