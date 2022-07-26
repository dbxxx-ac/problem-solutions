/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-04-29 10:48:00 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-05-02 01:10:17
 */
#include <iostream>
#include <cstdio>

void solve(int x1, int y1, int x2, int y2, int n) {
    if(n == 1) return ;
    if(x1 - x2 < (n >> 1)) {
        if(y1 - y2 < (n >> 1)) {
            std :: cout << (x2 + (n >> 1)) << ' ' << (y2 + (n >> 1)) << ' ' << 1 << std :: endl;
            solve(x1, y1, x2, y2, (n >> 1));
            solve(x2 + (n >> 1) - 1, y2 + (n >> 1), x2, y2 + (n >> 1), (n >> 1));
            solve(x2 + (n >> 1), y2 + (n >> 1) - 1, x2 + (n >> 1), y2, (n >> 1));
            solve(x2 + (n >> 1), y2 + (n >> 1), x2 + (n >> 1), y2 + (n >> 1), (n >> 1));
        } else {
            std :: cout << (x2 + (n >> 1)) << ' ' << (y2 + (n >> 1) - 1) << ' ' << 2 << std :: endl;
            solve(x2 + (n >> 1) - 1, y2 + (n >> 1) - 1, x2, y2, (n >> 1));
            solve(x1, y1, x2, y2 + (n >> 1), (n >> 1));
            solve(x2 + (n >> 1), y2 + (n >> 1) - 1, x2 + (n >> 1), y2, (n >> 1));
            solve(x2 + (n >> 1), y2 + (n >> 1), x2 + (n >> 1), y2 + (n >> 1), (n >> 1));    
        }
    } else {
        if(y1 - y2 < (n >> 1)) {
            std :: cout << (x2 + (n >> 1) - 1) << ' ' << (y2 + (n >> 1)) << ' ' << 3 << std :: endl;
            solve(x2 + (n >> 1) - 1, y2 + (n >> 1) - 1, x2, y2, (n >> 1));
            solve(x2 + (n >> 1) - 1, y2 + (n >> 1), x2, y2 + (n >> 1), (n >> 1));
            solve(x1, y1, x2 + (n >> 1), y2, (n >> 1));
            solve(x2 + (n >> 1), y2 + (n >> 1), x2 + (n >> 1), y2 + (n >> 1), (n >> 1));
        } else {
            std :: cout << (x2 + (n >> 1) - 1) << ' ' << (y2 + (n >> 1) - 1) << ' ' << 4 << std :: endl;
            solve(x2 + (n >> 1) - 1, y2 + (n >> 1) - 1, x2, y2, (n >> 1));
            solve(x2 + (n >> 1) - 1, y2 + (n >> 1), x2, y2 + (n >> 1), (n >> 1));
            solve(x2 + (n >> 1), y2 + (n >> 1) - 1, x2 + (n >> 1), y2, (n >> 1));
            solve(x1, y1, x2 + (n >> 1), y2 + (n >> 1), (n >> 1));
        }
    }
}

int main() {
    int k, x, y;
    std :: cin >> k >> x >> y;
    solve(x, y, 1, 1, 1 << k);
    return 0;
}