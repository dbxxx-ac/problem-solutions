/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-15 15:16:06 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-16 03:28:42
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

const int maxn = 5e5 + 5;
int a[maxn * 2];
int n;

inline int flip(int x) {
    return n * 2 - x + 1;
}

std :: deque <int> s, t;
char ans[maxn * 2];

void solve() {
    for (int i = 1; i <= n; ++i) {
        int sf = -1, sb = -2, tf = -3, tb = -4;
        if (!s.empty()) {
            sf = s.front();
            sb = s.back();
        }
        if (!t.empty()) {
            tf = t.front();
            tb = t.back();
        }
        if (s.size() > 1 && sf == sb) {
            ans[i] = ans[flip(i)] = 'L';
            s.pop_front();
            s.pop_back();
        } else if (sf == tb) {
            ans[i] = 'L';
            ans[flip(i)] = 'R';
            s.pop_front();
            t.pop_back();
        } else if (tf == sb) {
            ans[i] = 'R';
            ans[flip(i)] = 'L';
            s.pop_back();
            t.pop_front();
        } else if (t.size() > 1 && tf == tb) {
            ans[i] = ans[flip(i)] = 'R';
            t.pop_front();
            t.pop_back();
        } else {
            ans[0] = 'N';
            return ;
        }
    }
    ans[n * 2] = 'L';
    return ;
}

int main() {
    int T = read();
    while (T--) {
        s.clear();
        t.clear();
        std :: memset(ans, 0, sizeof(ans));
        ans[0] = 'Y';
        n = read();
        for (int i = 1; i <= n * 2; ++i)
            a[i] = read();
        
        bool chg = true;
        s.push_back(a[1]);
        for (int i = 2; i <= n * 2; ++i) {
            if (a[i] == a[1])
                chg = false;
            if (chg)
                s.push_back(a[i]);
            else
                t.push_front(a[i]);
        }

        solve();

        if (ans[0] == 'Y') {
            puts(ans + 1);
            continue;
        }
        
        s.clear();
        t.clear();
        ans[0] = 'Y';
        chg = true;
        for (int i = 1; i <= n * 2 - 1; ++i) {
            if (a[i] == a[n * 2])
                chg = false;
            if (chg)
                s.push_back(a[i]);
            else
                t.push_front(a[i]);
        }
        t.push_front(a[n * 2]);
        
        solve();

        puts((ans[0] == 'Y') ? (ans + 1) : "-1");
    }

    return 0;
}

/*
1
5
4 1 2 4 5 3 1 2 3 5
*/