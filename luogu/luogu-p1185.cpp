/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-08-14 15:00:06 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-08-14 22:10:56
 */

//之前写的解法太辣鸡，且死活查不出错，这里参照了类似于KHIN神的方法。
//由神仙xk帮忙debug，并不是抄袭。qwq
//链接：https://www.luogu.com.cn/blog/236807/Solution-luogu-P1185
//顺便 % 一下KHIN神
#include <iostream>
#include <cstdio>

const int maxn = 12;
const int maxm = 12;

bool isErased[maxm][1 << maxm];
int pos[2][1 << maxm];

int main() {
    int n, m;
    std :: scanf("%d%d", &m, &n);
    
    pos[0][0] = (1 << m) - (1 << m - 2);

    for (int i = 0; i < n; ++i) {
        int x, y;
        std :: scanf("%d%d", &x, &y);
        isErased[x - 1][y - 1] = true;
    }

    for (int i = 1; i < m; ++i)
        for (int j = 0; j < 1 << i; ++j)
            if(isErased[i - 1][j >> 1])
                isErased[i][j] = true;

    for (int i = 1; i < pos[0][0]; ++i, putc(' ', stdout));
    puts("o");
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < 1 << i; ++j)
            pos[1][j] = pos[0][j >> 1] + (j & 1 ? 1 : -1);
        std :: swap(pos[0], pos[1]);

        for (int k = 1; k < std :: max((1 << m - i) - (1 << m - i - 2), 2) ; ++k) {
            for (int j = 1, l = 0; l < 1 << i; ++j)
                if (j == pos[0][l]) {
                    putchar(isErased[i][l] ? ' ' : (l & 1 ? '\\' : '/'));
                    pos[0][l] += l & 1 ? 1 : -1;
                    ++l;
                } else
                    putchar(' ');
            puts("");
        }

        for (int j = 1, k = 0; k < 1 << i; ++j)
            putchar(j == pos[0][k] && !isErased[i][k++] ? 'o' : ' ');
        puts("");
    }
    return 0;
}