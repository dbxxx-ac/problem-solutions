#include <iostream>
#include <cstdio>
#include <algorithm>

const int maxn = 10005;
int a[maxn];

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
    while(m--) std :: next_permutation(a + 1,a + n + 1);
    for(int i = 1; i <= n; i++) printf("%d ",a[i]);
    printf("\n");
    return 0;
}