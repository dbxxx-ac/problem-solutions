/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-02-23 13:23:05 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-02-23 15:36:12
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

const int maxn = 15;
int sudoku[maxn][maxn],score[maxn][maxn];
int first[85];
int ans;
bool visc[maxn][maxn],visr[maxn][maxn],visg[maxn][maxn];
bool fnd;

inline int max(int a,int b) {
    return a > b ? a : b;
}

struct row {
    int ind,zero;
}r[maxn];

bool cmp(row a,row b) {
    return a.zero < b.zero;
}

int cal() {
    int ret = 0;
    for(int i = 1; i <= 9; i++) 
        for(int j = 1; j <= 9; j++)
            ret += sudoku[i][j] * score[i][j];
    return ret;
}

void dfs(int step) {
    if(step > 81) {
        fnd = true;
        ans = max(ans,cal());
        return ;
    }
    
    int x = first[step] / 9 + 1;
    int y = first[step] % 9;
    if(!y) {
        x--;
        y = 9;
    }
    if(sudoku[x][y]) dfs(step + 1);
    else {
        for(int i = 1; i <= 9; i++) {
            if(!visc[x][i] && !visr[y][i] && !visg[(x - 1) / 3 * 3 + (y - 1) / 3 + 1][i]) {
                sudoku[x][y] = i;
                visc[x][i] = visr[y][i] = visg[(x - 1) / 3 * 3 + (y - 1) / 3 + 1][i] = true;
                dfs(step + 1);
                sudoku[x][y] = 0;
                visc[x][i] = visr[y][i] = visg[(x - 1) / 3 * 3 + (y - 1) / 3 + 1][i] = false;                
                //printf("lalalalala\n");
            }
        }
    }
}

int main() {
    for(int i = 1; i <= 9; i++) {
        int zero = 0;
        for(int j = 1; j <= 9; j++) {
            scanf("%d",&sudoku[i][j]);
            if(!sudoku[i][j]) zero++;
            else {
                visc[i][sudoku[i][j]] = true;
                visr[j][sudoku[i][j]] = true;
                visg[(i - 1) / 3 * 3 + (j - 1) / 3 + 1][sudoku[i][j]] = true;         
            }
        }
        r[i].ind = i;
        r[i].zero = zero;
    }
    std :: sort(r+1,r+10,cmp);
        
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            int x = r[i].ind;
            int y = j;
            first[i * 9 - 9 + j] = x * 9 - 9 + y;
        }
    }

    for(int i = 1,j = 10 - i; i <= 5; i++,j--)
        for(int k = i; k <= j; k++)
            score[i][k] = score [k][i] = score[k][j] = score[j][k] = i + 5;

    dfs(1);
    if(fnd) printf("%d\n",ans);
    else printf("-1\n");
    return 0;
}