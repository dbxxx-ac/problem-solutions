/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-20 10:21:44 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-20 10:27:40
 */
#include <iostream>
#include <cstdio>
#include <deque>
#include <utility>

const int maxn = 1000005;
typedef std :: pair <int, int> Pair;

std :: deque <Pair> MaxQ, MinQ;
int a[maxn];

int main() {
    int n, k;
    std :: scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i)
        std :: scanf("%d", &a[i]);
    
    for (int i = 1; i <= n; ++i) {
        while (!MinQ.empty() && MinQ.back().first >= a[i])
            MinQ.pop_back();
        MinQ.push_back(std :: make_pair(a[i], i));
        if (MinQ.front().second == i - k)
            MinQ.pop_front();
        if (i >= k)
            std :: printf("%d ", MinQ.front().first);
    }

    puts("");

    for (int i = 1; i <= n; ++i) {
        while (!MaxQ.empty() && MaxQ.back().first <= a[i])
            MaxQ.pop_back();
        MaxQ.push_back(std :: make_pair(a[i], i));
        if (MaxQ.front().second == i - k)
            MaxQ.pop_front();
        if (i >= k)
            std :: printf("%d ", MaxQ.front().first);
    }

    puts("");
    return 0;
}