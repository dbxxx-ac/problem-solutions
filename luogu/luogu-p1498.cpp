/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-02-23 16:14:17 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-02-23 16:32:21
 */
#include <iostream>
#include <cstdio>
#include <cstring>

const int maxn = 2055;
char a[maxn][maxn];

int qpow(int a,int p) {
    int ans = 1, base = a;
    while(p) {
        if(p & 1) ans *= base;
        base *= base;
        p >>= 1;
    }
    return ans;
}

void draw(int x,int y,int depth) {
    if(depth == 1) {
        a[x][y] = a[x - 1][y + 1] = '/';
        a[x][y + 1] = a[x][y + 2] = '_';
        a[x][y + 3] = a[x - 1][y + 2] = '\\';
        return ;
    }
    int h = qpow(2,depth);
    draw(x,y,depth-1);
    draw(x,y + h,depth-1);
    draw(x - (h >> 1),y + (h >> 1),depth-1);
}

int main() {
    int n;
    scanf("%d",&n);
    memset(a,' ',sizeof(a));

    int h = qpow(2,n);
    draw(h,1,n);
    for(int i = 1; i <= h; i++,puts(""))
        for(int j = 1; j <= h * 2; j++)
            printf("%c",a[i][j]);
    printf("\n");
    return 0;
}