/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-04-02 09:21:07 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-04-02 09:29:53
 */
#include <iostream>
#include <cstdio>
#include <iomanip>

const int maxr = 25;
int a[maxr], idx = 1;
int n, r;

void dfs(int startx) {
    if(idx == r + 1) {
        for(int i = 1; i <= r; i++)
            std :: cout << std :: setw(3) << a[i];
        std :: cout << std :: endl; 
        return ;
    }
    for(int i = startx; i <= n; i++) {
        a[idx++] = i;
        dfs(i + 1);
        idx--;
    }
    return ;
}

int main() {
    std :: cin >> n >> r;
    dfs(1);
    return 0;
}