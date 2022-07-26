#include <iostream>
#include <cstdio>

const int maxn = 105;
const int maxm = 10005;
int n, m, a[maxn], dp[maxm] = {1};

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for(int i = 1; i <= n; i++)
        for(int j = m; j >= a[i]; j--)
            dp[j] += dp[j - a[i]];
            
    printf("%d\n", dp[m]);
    return 0;
}