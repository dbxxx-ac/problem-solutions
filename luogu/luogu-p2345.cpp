/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-11-03 18:06:25 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-11-04 10:16:54
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

const int maxn = 20005;
struct COW {
    int x, v;
    const bool operator < (const COW& b) {
        return this -> v < b.v;
    }
}a[maxn], tmp[maxn];

long long ans = 0;
void merge(int l, int r) {
    if (l == r)
        return ;
    int mid = l + r >> 1;
    merge(l, mid);
    merge(mid + 1, r);

    long long slx = 0, srx = 0;
    for (int i = l; i <= mid; ++i)
        slx += a[i].x;
    int j = l;
    for (int i = mid + 1; i <= r; ++i) {
        while (j <= mid && a[j].x < a[i].x) {
            srx += a[j].x;
            slx -= a[j++].x;
        }
        ans += (a[i].x * (j - l) * 1LL - srx - a[i].x * (mid - j + 1) * 1LL + slx) * a[i].v;
    }//处理答案，有点类似于two-pointers

    int i = l, k = l;
    j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i].x <= a[j].x) 
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }
    while (i <= mid)
        tmp[k++] = a[i++];
    while (j <= r)
        tmp[k++] = a[j++];
    for (int i = l; i <= r; ++i)
        a[i] = tmp[i];
    //按照x进行merge sort 这里应该很熟悉了
}

int main() {
    int n;
    std :: scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        std :: scanf("%d %d", &a[i].v, &a[i].x);
    
    std :: sort(a + 1, a + 1 + n);
    merge(1, n);
    std :: printf("%lld\n", ans);
    return 0;
}