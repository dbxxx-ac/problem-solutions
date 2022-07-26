/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-18 18:17:23 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-18 18:21:37
 */
#include <iostream>
#include <cstdio>
#include <utility>
#include <deque>

typedef std :: pair <int, int> Pair;
std :: deque <Pair> q;

const int maxn = 2000005;
int a[maxn];

int main() {
    int n, m;
    std :: scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        std :: scanf("%d", &a[i]);
    
    if (n >= 1) puts("0");

    for (int i = 1; i <= n - 1; ++i) {
        while (!q.empty() && q.back().first >= a[i])
            q.pop_back();
        q.push_back(std :: make_pair(a[i], i));
        if (q.front().second == i - m)
            q.pop_front();
        std :: printf("%d\n", q.front().first);
    }

    return 0;
}