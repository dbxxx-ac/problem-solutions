/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-02-22 10:47:49 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-02-22 10:47:49 
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>

int n,m;
int startx,starty,endx,endy,dir;
bool vis[20005];
int state[55][55];
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};

struct node{
    int x,y,d,step;
};

std :: queue <node> q;

int getkey(int x,int y,int dir){
    return dir * 2500 + x * 50 + y;
}

bool valid(int x,int y,int dir){
    if(x <= 0 || y <= 0 || x >= n || y >= m || state[x][y] ||
                state[x+1][y] ||
                state[x+1][y+1] ||
                state[x][y+1]) return false;
    return true;
}

void bfs(){
    switch(dir){
        case 'N': dir = 0; break;
        case 'E': dir = 1; break;
        case 'S': dir = 2; break;
        case 'W': dir = 3; break;
        default: dir = 10086; break;
    }

    node now;
    now.x = startx;
    now.y = starty;
    now.d = dir;
    now.step = 0;
    q.push(now);

    while(!q.empty()){
        now = q.front();
        q.pop();
        int nowx = now.x;
        int nowy = now.y;
        int dir = now.d;
        //printf("%d %d %d \n",nowx,nowy,dir);
        int key = getkey(nowx,nowy,dir);
        if(nowx == endx && nowy == endy){
            printf("%d\n",now.step);
            exit(0);
        }
        //std :: cout << "Getting key done:"<<key << std :: endl;
        if(vis[key]) continue;
        vis[key] = true;
        
        node nxt;
        nxt.step = now.step + 1;
        int nxtx = now.x;
        int nxty = now.y;
        nxt.x = nxtx;
        nxt.y = nxty;
        nxt.d = (dir + 3) % 4;
        q.push(nxt);
        nxt.d = (dir + 5) % 4;
        q.push(nxt);

        nxt.d = dir;
        for(int i = 1; i <= 3; i++){
            nxtx = nowx + dx[dir] * i;
            nxty = nowy + dy[dir] * i;
            if(!valid(nxtx,nxty,dir)) break;
            nxt.x = nxtx;
            nxt.y = nxty;
            q.push(nxt);
        }
    }

    printf("-1\n");
    return ;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            scanf("%d",&state[i][j]);
            if(!state[i][j]) continue;
            for(int dir = 0; dir <= 3; dir++){
                state[i][j] = true;
                state[i+1][j] = true;
                state[i+1][j+1] = true;
                state[i][j+1] = true;
            }
        }
    scanf("%d %d %d %d %c",&startx,&starty,&endx,&endy,&dir);
    bfs();
    return 0;
}