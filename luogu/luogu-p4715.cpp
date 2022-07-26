/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-07-18 15:52:33 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-07-19 22:10:27
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

const int maxn = 8;

struct team {
    int ability;
    int num;
    bool operator < (const team &b) const {
        return this -> ability < b.ability;
    }
}a[1 << maxn];

int main() {
    int n;
    std :: cin >> n;
    for (int i = 1; i <= (1 << n); ++i) {
        std :: cin >> a[i].ability;
        a[i].num = i;
    }

    int left_max_id = 1, right_max_id = (1 << n >> 1) + 1;

    for (int i = 1; i <= (1 << n >> 1); ++i)
        if (a[i].ability > a[left_max_id].ability)
            left_max_id = i;
    
    for (int i = (1 << n >> 1) + 1; i <= (1 << n); ++i)
        if (a[i].ability > a[right_max_id].ability)
            right_max_id = i;
    
    std :: cout << (a[left_max_id].ability < a[right_max_id].ability ? left_max_id : right_max_id) << std :: endl;
    return 0;
}