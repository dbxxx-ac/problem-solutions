/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-04-02 02:20:50 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-04-02 02:25:40
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

const int maxn = 105;

struct people {
    int y, m, d, num;
    std :: string name;
    bool operator < (const people &b) const {
        if(this -> y != b.y) return this -> y < b.y;
        if(this -> m != b.m) return this -> m < b.m;
        if(this -> d != b.d) return this -> d < b.d;
        return this -> num > b.num;
    }
}a[maxn];

int main() {
    int n;
    std :: cin >> n;
    for(int i = 1; i <= n; i++) {
        std :: cin >> a[i].name >> a[i].y >> a[i].m >> a[i].d;
        a[i].num = i;
    }
    std :: sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) 
        std :: cout << a[i].name << std :: endl;
    return 0;
}