/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-08-19 00:27:02 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-08-19 01:13:48
 */
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

const int maxb = 100005;

bool isprime[maxb];
int prime_num[maxb];
int fa[maxb];

void prime(int n) {
    std :: memset(isprime, true, sizeof(isprime));
    isprime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (isprime[i]) prime_num[++prime_num[0]] = i;
        for (int j = 1; j <= prime_num[0] && i * prime_num[j] <= n; ++j) {
            isprime[i * prime_num[j]] = false;
            if (i % prime_num[j] == 0) break;
        }
    }
}

int find(int x) {
    while (x != fa[x]) x = fa[x] = fa[fa[x]];
    return x;
}

int main() {
    int a, b, p;
    std :: scanf("%d%d%d", &a, &b, &p);
    prime(b);

    for (int i = 1; i <= b; ++i) {
        fa[i] = i;
    }
    
    for (int i = 1; i <= prime_num[0]; ++i) {
        if (prime_num[i] >= p) {
            for (int j = std :: ceil(a * 1.0 / prime_num[i]); j * prime_num[i] <= b; ++j) {
                int fax = find(prime_num[i]);
                int fay = find(j * prime_num[i]);
                fa[fax] = fay;
            } 
        }
    }

    int ans = 0;
    for (int i = a; i <= b; ++i)
        if (fa[i] == i)
            ++ans;
    
    std :: printf("%d\n", ans);
    return 0;
}