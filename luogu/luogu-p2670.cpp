/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-03-13 12:36:51 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-03-13 12:49:04
 */
#include <iostream>
#include <cstdio>

const int maxn = 105;
const int maxm = 105;
int n,m;
char a[maxn][maxm];

int getnum(int x, int y) {
    int dx[9] = {0, 1, 1, 1, 0, 0, -1, -1, -1};
    int dy[9] = {0, 1, 0, -1, 1, -1, 1, 0, -1};
    int ans = 0;
    for(int i = 1; i <= 8; i++)
        if(x + dx[i] > 0 && x + dx[i] <= n && y + dy[i] > 0 && y + dy[i] <= m && a[x + dx[i]][y + dy[i]] == '*')
            ans++;
    return ans;
}

int main() {
    std :: cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            std :: cin >> a[i][j];
    
    for(int i = 1; i <= n; i++, puts(""))
        for(int j = 1; j <= m; j++)
            if(a[i][j] == '?') std :: cout << getnum(i,j);
            else putchar('*');
    
    return 0;
}