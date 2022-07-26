/*
 * @Author: crab-in-the-northeast 
 * @Date: 2021-02-18 23:49:51 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2021-02-19 01:31:40
 */
#include <bits/stdc++.h>
inline int read() {
    int x = 0;
    bool flag = true;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            flag = false;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if(flag)
        return x;
    return ~(x - 1);
}

const int maxn = 100005;

int a[maxn], b[maxn];

struct node {
    int sum;
    int aidx, bidx;
    const bool operator < (const node &b) const {
        return this -> sum > b.sum;
    }
};

std :: priority_queue <node> pq;

void insert(int aidx, int bidx) {
    pq.push((node){a[aidx] + b[bidx], aidx, bidx});
}
int main() {
    int n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    for (int i = 1; i <= n; ++i) {
        b[i] = read();
        insert(1, i);
    }
    
    for (int i = 1; i <= n; ++i) {
        node now = pq.top();
        printf("%d ", now.sum);
        pq.pop();
        insert(now.aidx + 1, now.bidx);
    }

    puts("");
    return 0;
}