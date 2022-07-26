/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-03-07 10:37:45 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-03-07 12:15:19
 */
#include <iostream>
#include <cstdio>

struct node {
    int l, r;
}l[100005];

void InitList(int n) {
    for(int i = 1; i <= n; i++)
        l[i].l = l[i].r = -1;
    l[0].r = 1;
    l[1].l = 0;
    return ;
}

void addLeft(int x, int pos) {
    l[x].r = pos;
    l[x].l = l[pos].l;
    l[l[pos].l].r = x;
    l[pos].l = x;
    return ;
}

void addRight(int x, int pos) {
    l[x].l = pos;
    l[x].r = l[pos].r;
    l[l[pos].r].l = x;
    l[pos].r = x;
    return ;
}

void DeleteNode(int x) {
    if(l[x].l != -1) {
        l[l[x].l].r = l[x].r;
        l[l[x].r].l = l[x].l;
        l[x].l = -1;
        l[x].r = -1;
    }
    return ;
}

void printList() {
    int x = l[0].r;
    printf("%d ",x);
    while(l[x].r != -1) {
        x = l[x].r;
        printf("%d ", x);
    }
    return ;
}

int main() {
    int n;
    scanf("%d",&n);
    InitList(n);

    for(int i = 2; i <= n; i++) {
        int pos, dir;
        scanf("%d %d",&pos, &dir);
        if(dir) addRight(i, pos);
        else addLeft(i, pos);
    }

    int m;
    scanf("%d",&m);
    for(int i = 1; i <= m; i++) {
        int x;
        scanf("%d",&x);
        DeleteNode(x);
    }
    printList();
    return 0;
}