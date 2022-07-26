/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-11-01 17:04:02 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-11-01 17:04:02 
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

const int maxn = 100005;
const int mod = (int)1e8 - 3;

struct match {
    int height;
    int num;
    const bool operator < (match &b) {
        return this -> height < b.height;
    }
}a[maxn], b[maxn];

long long ans = 0;
int q[maxn], tmp[maxn];

void merge_sort(int l, int r) {
    if (l == r)
        return ;
    int mid = l + r >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);

    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j])
            tmp[k++] = q[i++];
        else {
            tmp[k++] = q[j++];
            ans = (ans - i + mid + 1) % mod;
        }
    }

    while (i <= mid)
        tmp[k++] = q[i++];
    while (j <= r)
        tmp[k++] = q[j++];
    
    for (int i = l; i <= r; ++i)
        q[i] = tmp[i];
    return ;
}

int main() {
    int n;
    std :: scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        std :: scanf("%d", &a[i].height);
    for (int i = 1; i <= n; ++i)
        std :: scanf("%d", &b[i].height);
    for (int i = 1; i <= n; ++i)
        a[i].num = b[i].num = i;
    
    std :: sort(a + 1, a + 1 + n);
    std :: sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; ++i)
        q[a[i].num] = b[i].num;
    merge_sort(1, n);
    std :: printf("%lld\n", ans);
    return 0;
}