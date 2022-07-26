/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-03-27 22:02:47 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-03-27 22:25:17
 */
#include <iostream>
#include <cstdio>

char g[15][15];
bool vis[200005];
int ans;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

struct node {
    int x, y, dir;
}cow, john;

int GetKey() {
    return john.dir * 40000 + cow.dir * 10000 + (john.y - 1) * 1000 + (john.x - 1) * 100 + (cow.y - 1) * 10 + cow.x - 1;
}

int main() {
    for(int i = 1; i <= 10; i++) {
        scanf("%s", g[i] + 1);
        for(int j = 1; j <= 10; j++)
            if(g[i][j] == 'C') {
                cow.x = i;
                cow.y = j;
            }else if(g[i][j] == 'F') {
                john.x = i;
                john.y = j;
            }
    }
    for(int i = 0; i <= 11; i++)
        g[0][i] = g[i][0] = g[11][i] = g[i][11] = '*';
    cow.dir = 0;
    john.dir = 0;

    while(cow.x != john.x || cow.y != john.y) {
        if(vis[GetKey()]) {
            puts("0");
            return 0;
        }
        vis[GetKey()] = true;
        if(g[cow.x + dx[cow.dir]][cow.y + dy[cow.dir]] == '*') cow.dir = (cow.dir + 1) % 4;
        else {
            cow.x += dx[cow.dir];
            cow.y += dy[cow.dir];
        }
        if(g[john.x + dx[john.dir]][john.y + dy[john.dir]] == '*') john.dir = (john.dir + 1) % 4;
        else {
            john.x += dx[john.dir];
            john.y += dy[john.dir];
        }
        ans++;
    }

    printf("%d\n", ans);
    return 0;
}