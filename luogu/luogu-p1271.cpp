/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-04-02 01:58:30 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-04-02 02:01:13
 */
#include <iostream>
#include <cstdio>

const int maxn = 1005;
int a[maxn];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int t;
        scanf("%d", &t);
        a[t]++;
    }
    for(int i = 1; i <= n; i++)
        while(a[i]--)
            printf("%d ", i);
    return 0;
}