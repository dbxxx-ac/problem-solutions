/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-17 19:04:13 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-17 20:28:32
 */
#include <iostream>
#include <cstdio>
#include <utility>
#include <deque>
#include <functional>

typedef std :: pair<int, int> Pair;

std :: deque <Pair> q;

const int maxn = 2000005;
int a[maxn];

int main() {
    int n, k;
    std :: scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i)
        std :: scanf("%d", &a[i]);
    
    for (int i = 1; i <= n; ++i) {
        while (!q.empty() && q.back().first <= a[i])
            q.pop_back();
        q.push_back(std :: make_pair(a[i], i));
        if (q.front().second == i - k)
            q.pop_front();
        if (i >= k)
            std :: printf("%d\n", q.front().first);
    }

    return 0;
}