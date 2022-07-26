/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-04-28 11:24:59 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-04-28 13:32:37
 */
#include <iostream>
#include <cstdio>

const int maxn = 105;

int n;
char s[maxn * 2 + 5];
int empty_idx;//empty_idx记录的是两个空位中的前面那个空位的下标。

void print() {//输出函数
    for(int i = 1; i <= 2 * n + 2; i++)
        std :: cout << s[i];
    std :: cout << std :: endl;
    return ;
}

void init() {//初始化函数
    for(int i = 1; i <= n; i++) s[i] = 'o';
    for(int i = n + 1; i <= 2 * n; i++) s[i] = '*';
    for(int i = 2 * n + 1; i <= 2 * n + 2; i++) s[i] = '-';
    empty_idx = 2 * n + 1;
    print();//别忘了最初情况也需要输出
    return ;
}

void move(int x) {//移动函数
    s[empty_idx] = s[x];
    s[empty_idx + 1] = s[x + 1];
    s[x] = s[x + 1] = '-';
    empty_idx = x;
    print();
}
//move(x)的效果：将第x个棋与第x + 1个棋一起分别移到两个空位上

void solve(int k) {//分治函数
    if(k == 4) {
        move(4);
        move(8);
        move(2);
        move(7);
        move(1);
        //k=4的情况就是完全照葫芦画瓢咯。
    } else {
        move(k);//先把中间的移最后
        move(2 * k - 1);//再移后边的两个*移中间
        solve(k - 1);//分治
    }
}

int main() {
    std :: cin >> n;//读入
    init();//初始化
    solve(n);//调用分治
    return 0;
}