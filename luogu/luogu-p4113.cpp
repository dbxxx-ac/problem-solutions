/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-26 10:12:46 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-26 10:34:50
 */
#include <bits/stdc++.h>
inline int read() {
    int x = 0;
    bool flag = true;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-')
            flag = false;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if(flag)
        return x;
    return ~(x - 1);
}
inline int lowbit(int x) {
    return x & (-x);
}

const int maxn = (int)2e6 + 5;
const int maxm = (int)2e6 + 5;
const int maxc = (int)2e6 + 5;

int a[maxn], lst[maxc], ltt[maxc];

typedef std :: pair <int, int> pii;
std :: vector <pii> ques[maxn];

int n;
int fwk[maxn];

inline void add(int x, int v) {
    for (; x <= n; x += lowbit(x))
        fwk[x] += v;
}

inline int get(int x) {
    int ans = 0;
    for (; x; x -= lowbit(x))
        ans += fwk[x];
    return ans;
}

int ans[maxm];

int main() {
    n = read();
    int c = read(), m = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    
    for (int i = 1; i <= m; ++i) {
        int l = read(), r = read();
        ques[r].emplace_back(l, i);
    }

    std :: fill(lst + 1, lst + c + 1, n + 1);
    std :: fill(ltt + 1, ltt + c + 1, n + 1);
    
    for (int r = 1; r <= n; ++r) {
        int x = a[r];
        add(ltt[x], -1);
        add(lst[x], 1);
        ltt[x] = lst[x];
        lst[x] = r;
        
        for (pii que : ques[r]) {
            int l = que.first, id = que.second;
            ans[id] = get(r) - get(l - 1);
        }
    }

    for (int i = 1; i <= m; ++i)
        printf("%d\n", ans[i]);
    
    return 0;
}