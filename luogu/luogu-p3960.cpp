/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-27 16:07:43 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-27 17:09:25
 */
#include <bits/stdc++.h>
#define int long long
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

const int maxn = (int)3e5 + 5;
const int maxm = (int)3e5 + 5;
const int maxq = (int)3e5 + 5;

struct fenwick {
    int lim;
    int bit[maxn + maxm + maxq];

    inline void add(int x, int v) {
        for (; x <= lim; x += lowbit(x))
            bit[x] += v;
    }

    inline int kth(int k) {
        int ans = 0, sum = 0;
        for (int i = 20; ~i; --i) {
            ans += (1 << i);
            if (ans > lim || sum + bit[ans] >= k)
                ans -= (1 << i);
            else
                sum += bit[ans];
        }
        return ans + 1;
    }
} ve, ho;

typedef std :: pair <int, int> pii;

pii qts[maxq];
bool ism[maxq];
std :: vector <int> qt[maxn];
std :: vector <int> mdy;

std :: vector <int> veno[maxn];
std :: vector <int> homo;

signed main() {
    int n = read(), m = read(), q = read();
    ve.lim = m + q;
    ho.lim = n + q;

    for (int i = 1; i <= ve.lim; ++i)
        ve.bit[i] = lowbit(i);
    for (int i = 1; i <= ho.lim; ++i)
        ho.bit[i] = lowbit(i);
    
    homo.push_back(0);
    for (int i = 1; i <= n; ++i)
        homo.push_back(i * m);
    
    for (int i = 1; i <= q; ++i) {
        int x = read(), y = read();
        if (y == m)
            ism[i] = true;
        qts[i] = std :: make_pair(x, y);
        qt[x].push_back(i);
    }

    for (int x = 1; x <= n; ++x) {
        for (auto id : qt[x]) {
            if (ism[id])
                continue;
            int y = qts[id].second;
            y = ve.kth(y);
            ve.add(y, -1);
            mdy.push_back(y);
            qts[id].second = y;
        }

        for (int y : mdy)
            ve.add(y, 1);
        mdy.clear();
    }

    for (int i = 1; i <= q; ++i) {
        int x = qts[i].first, y = qts[i].second;
        int num = 0;
        if (!ism[i]) {
            if (y < m)
                num = (x - 1) * m + y;
            else
                num = veno[x][y - m];
        }

        int coy = ho.kth(x);
        ho.add(coy, -1);

        int nw = homo[coy];
        
        if (ism[i])
            num = nw;
        else
            veno[x].push_back(nw);
        
        printf("%lld\n", num);
        homo.push_back(num);
    }

    return 0;
}
