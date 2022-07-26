/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-04-02 02:03:26 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-04-02 02:10:19
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

const int maxn = 50000005;

int a[maxn];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    std :: nth_element(a + 1, a + k + 1, a + 1 + n);
    printf("%d\n", a[k + 1]);
    return 0;
}
