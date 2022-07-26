/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-04-02 21:52:34 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-04-02 22:13:36
 */
#include <iostream>
#include <cstdio>

const int maxr = 105;
const int maxc = 105;

char g[maxr][maxc];

int main() {
    int r, c, k, ans = 0;
    std :: cin >> r >> c >> k;
    for(int i = 1; i <= r; i++) 
        scanf("%s", g[i] + 1);
    for(int i = 1; i <= r; i++) {
        int len = 0;
        for(int j = 1; j <= c + 1; j++) {
            if(g[i][j] == '.') len++;
            else {
                if(k <= len) ans += len - k + 1;
                len = 0;
            }
        }
    }
    if(k == 1) {
        std :: cout << ans << std :: endl;
        return 0;        
    }
    for(int i = 1; i <= c; i++) {
        int len = 0;
        for(int j = 1;  j <= r + 1; j++) {
            if(g[j][i] == '.') len++;
            else {
                if(k <= len) ans += len - k + 1;
                len = 0;
            }
        }
    }
    std :: cout << ans << std :: endl;
    return 0;
}