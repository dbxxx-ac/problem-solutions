/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-11-20 23:36:45 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-11-21 01:00:02
 */
#include <bits/stdc++.h>

const int maxn = 100005;
const int maxlogn = 25;
const double eps = 0.0000001;

inline long long read() {
    long long x = 0;
    bool f = true;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = false;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if (f) 
        return x;
    return ~(x - 1);
}

int n;
long long A[maxn], B[maxn], disA[maxn], disB[maxn], distotA[maxn][maxlogn], distotB[maxn][maxlogn], curpos[maxn][maxlogn];

struct building {
    long long h;
    int num, lst, nxt;
    const bool operator < (const building& b) {
        return this -> h < b.h;
    }
}a[maxn];

int p[maxn];

inline void upddis(int spos, int s, int t) {
    if (t < 1 || t > n)
        return ;
    int dis = std :: abs(a[s].h - a[t].h);
    if (disB[spos] == 0 || disB[spos] > dis || (disB[spos] == dis && a[t] < a[p[B[spos]]])) {
        disA[spos] = disB[spos];
        disB[spos] = dis;
        A[spos] = B[spos];
        B[spos] = a[t].num;
    } else if (disA[spos] == 0 || disA[spos] > dis || (disA[spos] == dis && a[t] < a[p[A[spos]]])) {
        disA[spos] = dis;
        A[spos] = a[t].num;
    }
    return ;
}

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        a[i].num = i;
        a[i].h = read();
    }
    std :: sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i) {
        if (i != 1)
            a[i].lst = i - 1;
        if (i != n)
            a[i].nxt = i + 1;
        p[a[i].num] = i;
    }
    
    // solve disA, disB On
    for (int i = 1; i <= n; ++i) {
        int pos = p[i];
        upddis(i, pos, a[a[pos].lst].lst);
        upddis(i, pos, a[pos].lst);
        upddis(i, pos, a[pos].nxt);
        upddis(i, pos, a[a[pos].nxt].nxt);
        if (a[pos].lst)
            a[a[pos].lst].nxt = a[pos].nxt;
        if (a[pos].nxt)
            a[a[pos].nxt].lst = a[pos].lst;
        a[pos].lst = a[pos].nxt = 0;
    }

    //puts("fff");
    // solve distotA, distotB, Onlogn
    for (int i = 1; i <= n; ++i) {
        distotA[i][0] = disA[i];
        distotB[i][0] = disB[A[i]];
        curpos[i][0] = B[A[i]];
    }

    for (int j = 1; j <= maxlogn - 5; ++j)
        for (int i = 1; i <= n; ++i) {
            curpos[i][j] = curpos[curpos[i][j - 1]][j - 1];
            if (curpos[i][j]) {
                distotA[i][j] = distotA[i][j - 1] + distotA[curpos[i][j - 1]][j - 1];
                distotB[i][j] = distotB[i][j - 1] + distotB[curpos[i][j - 1]][j - 1];
            }
        }
    
    // solve Part1 nlogn
    long long x0 = read(), ans = 0;
    double minrat = INT_MAX;
    
    for (int i = 1; i <= n; ++i) {
        long long ansA = 0, ansB = 0, pos = i, tmpx = x0;
        for (int j = maxlogn - 5; j >= 0; --j) {
            if (distotA[pos][j] + distotB[pos][j] && tmpx >= distotA[pos][j] + distotB[pos][j]) {
                tmpx -= distotA[pos][j] + distotB[pos][j];
                ansA += distotA[pos][j];
                ansB += distotB[pos][j];
                pos = curpos[pos][j];
            }
        }
        if (disA[pos] <= tmpx)
            ansA += disA[pos];
        if (ansA == 0)
            continue;
        if (ans == 0 || minrat - 1.0 * ansA / ansB > eps || (fabs(minrat - 1.0 * ansA / ansB) <= eps && a[p[ans]] < a[p[i]])) {
            minrat = 1.0 * ansA / ansB;
            ans = i;
        }
    }
    std :: printf("%lld\n", ans);

    // solve Part2 mlogn
    int m = read();
    while (m--) {
        long long s = read(), x = read(), ansA = 0, ansB = 0;
        for (int j = maxlogn - 5; j >= 0; --j) {
            if (distotA[s][j] + distotB[s][j] && x >= distotA[s][j] + distotB[s][j]) {
                x -= distotA[s][j] + distotB[s][j];
                ansA += distotA[s][j];
                ansB += distotB[s][j];
                s = curpos[s][j];
            }
        }
        if (disA[s] <= x) 
            ansA += disA[s];
        std :: printf("%lld %lld\n", ansA, ansB);
    }

    return 0;
}

