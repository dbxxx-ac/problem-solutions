/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-31 12:46:05 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-01-31 13:44:31
 */
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int sudoku[15][15];
bool visc[15][15],visl[15][15],visg[15][15];

void input(){
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            scanf("%d",&sudoku[i][j]);
            if(sudoku[i][j]){
                visc[i][sudoku[i][j]]=true;
                visl[j][sudoku[i][j]]=true;
                visg[(i-1)/3*3+(j-1)/3+1][sudoku[i][j]]=true;
            }
        }
    }
}

void output(){
    for(int i=1;i<=9;i++,puts(""))
        for(int j=1;j<=9;j++,putchar(' '))
            printf("%d",sudoku[i][j]);
    exit(0);
}

void dfs(int x,int y){
    if(sudoku[x][y]){
        if(x==9&&y==9)
            output();
        if(y==9) dfs(x+1,1);
        else dfs(x,y+1);
        return ;
    }
    
    for(int i=1;i<=9;i++){
        if(!visc[x][i]&&!visl[y][i]&&!visg[(x-1)/3*3+(y-1)/3+1][i]){
            sudoku[x][y]=i;
            visc[x][i]=true;
            visl[y][i]=true;
            visg[(x-1)/3*3+(y-1)/3+1][i]=true;
            
            if(x==9&&y==9)
                output();
            if(y==9) dfs(x+1,1);
            else dfs(x,y+1);

            sudoku[x][y]=0;
            visc[x][i]=false;
            visl[y][i]=false;
            visg[(x-1)/3*3+(y-1)/3+1][i]=false;
        }
    }

}

int main(){
    input();
    dfs(1,1);    
    return 0;
}