/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-07-24 16:44:22 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-07-24 17:17:31
 */
#include <iostream>
#include <cstdio>

const int maxn = 500005;
const int inf = 2147483647;

struct node {
    int l, r;
    int val;
    int cnt;
    int siz;
} tree[maxn];

int cnt = 0;

void insert(int idx, int val) {
    tree[idx].siz++;
    if (tree[idx].val == val) {
        tree[idx].cnt++;
        return ;
    } else if (tree[idx].val > val) {
        if (tree[idx].l != 0) insert(tree[idx].l, val);
        else {
            tree[++cnt].val = val;
            tree[cnt].cnt = tree[cnt].siz = 1;
            tree[idx].l = cnt;
        }
    } else if (tree[idx].val < val) {
        if (tree[idx].r != 0) insert(tree[idx].r, val);
        else {
            tree[++cnt].val = val;
            tree[cnt].cnt = tree[cnt].siz = 1;
            tree[idx].r = cnt;
        }
    }
}

int getLast(int idx, int val, int ans) {
    if (tree[idx].val >= val) {
        if (tree[idx].l != 0) return getLast(tree[idx].l, val, ans);
        else return ans;
    } else {
        if (tree[idx].r == 0) return (tree[idx].val < val) ? tree[idx].val : ans;
        else if (tree[idx].cnt != 0) return getLast(tree[idx].r, val, tree[idx].val);
        else return getLast(tree[idx].r, val, ans);
    }
}

int getNext(int idx, int val, int ans) {
    if (tree[idx].val <= val) {
        if (tree[idx].r != 0) return getNext(tree[idx].r, val, ans);
        else return ans;
    } else {
        if (tree[idx].l == 0) return(tree[idx].val > val) ? tree[idx].val : ans;
        else if (tree[idx].cnt != 0) return getNext(tree[idx].l, val, tree[idx].val);
        else return getNext(tree[idx].l, val, ans);
    }
}

int getRankByVal(int idx, int val) {
    if (idx == 0) return 0;
    else if (tree[idx].val == val) return tree[tree[idx].l].siz + 1;
    else if (tree[idx].val > val) return getRankByVal(tree[idx].l, val);
    else return getRankByVal(tree[idx].r, val) + tree[tree[idx].l].siz + tree[idx].cnt;
}

int getValByRank(int idx, int rk) {
    if (idx == 0) return inf;
    else if (tree[tree[idx].l].siz >= rk) return getValByRank(tree[idx].l, rk);
    else if (tree[tree[idx].l].siz + tree[idx].cnt >= rk) return tree[idx].val;
    else return getValByRank(tree[idx].r, rk - tree[tree[idx].l].siz - tree[idx].cnt);
}

int main() {
    int n;
    std :: cin >> n;
    while (n--) {
        int op, idx;
        std :: scanf("%d%d", &op, &idx);
        if (op == 1) std :: printf("%d\n", getRankByVal(1, idx) + 1);
        else if (op == 2) std :: printf("%d\n", getValByRank(1, idx));
        else if (op == 3) std :: printf("%d\n", getLast(1, idx, -inf));
        else if (op == 4) std :: printf("%d\n", getNext(1, idx, inf));
        else {
            if (cnt == 0) {
                tree[++cnt].val = idx;
                tree[cnt].cnt = tree[cnt].siz = 1;
            } else insert(1, idx);
        }
    }
    return 0;
}