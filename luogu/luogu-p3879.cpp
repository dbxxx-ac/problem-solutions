/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-09-06 23:38:06 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-09-07 00:03:30
 */
#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>

std :: map <std :: string, std :: set<int> > a;

int main() {
    int n;
    std :: scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int l;
        std :: scanf("%d", &l);
        while (l--) {
            std :: string str;
            std :: cin >> str;
            a[str].insert(i);
        }
    }

    int m;
    std :: scanf("%d", &m);
    while (m--) {
        std :: string str;
        std :: cin >> str;
        int siz = a[str].size();
        for (std :: set <int> :: iterator iter = a[str].begin(); iter != a[str].end(); ++iter)
            std :: printf("%d ", *iter);
        putc('\n', stdout);
    }

    return 0;
}
