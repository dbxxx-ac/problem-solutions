/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-07-09 00:01:37 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-07-09 00:04:21
 */
#include <iostream>
#include <cstdio>
#include <map>

std :: map <int, std :: map <int, int> > a;

int main() {
    int n, q;
    std :: cin >> n >> q;
    while (q--) {
        int op, x, y;
        std :: cin >> op >> x >> y;
        if (op == 1) {
            int num;
            std :: cin >> num;
            a[x][y] = num;
        } else if (op == 2) {
            std :: cout << a[x][y] << std :: endl;
        }
    }

    return 0;
}