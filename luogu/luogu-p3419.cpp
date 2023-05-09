/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-05-03 08:54:20 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-05-03 09:24:19
 */
#include <bits/stdc++.h>
inline int read() {
    int x = 0;
    bool f = true;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            f = false;
    for (; isdigit(ch); ch = getchar())
        x = (x << 1) + (x << 3) + ch - '0';
    return f ? x : (~(x - 1));
}

const int N = (int)1e5 + 5;
const int P = (int)5e5 + 5;
int nxt[P], a[P];
int pos[N];
bool inq[N];

struct cmp {
    bool operator() (int a, int b) {
        return nxt[a] < nxt[b];
    }
};

int main() {
    int n = read(), k = read(), p = read();
    for (int i = 1; i <= p; ++i)
        a[i] = read();
    std :: memset(pos, 0x3f, sizeof(pos));
    for (int i = p; i; --i) {
        nxt[i] = pos[a[i]];
        pos[a[i]] = i;
    }
    
    std :: priority_queue <int, std :: vector <int>, cmp> q;
    int ans = 0;
    for (int i = 1; i <= p; ++i) {
        if (inq[a[i]]) {
            q.push(i);
            ++k;
            // 堆里值同为 a[i] 的那些元素，nxt 一定都不超过 i
            // 然而当 a[i] 不出现在堆中的时候，堆里 nxt 最大的一定超过了 i
            // 所以可以直接不改
        } else {
            if (q.size() == k) {
                inq[a[q.top()]] = false;
                q.pop();
            }
            q.push(i);
            inq[a[i]] = true;
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}