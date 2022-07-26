/*
 * @Author: crab-in-the-northeast 
 * @Date: 2021-02-19 01:53:40 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2021-02-19 10:16:55
 */
#include <bits/stdc++.h>
inline long long read() {
    long long x = 0;
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
    if (flag)
        return x;
    return ~(x - 1);
}

const int maxn = 150005;

struct building {
    long long t, T;
    bool operator < (const building &b) const {
        return this -> T < b.T;
    }
}a[maxn];

std :: priority_queue <long long> pq;

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i) {
        a[i].t = read();
        a[i].T = read();
    }
    
    std :: sort(a + 1, a + 1 + n);
    int ans = 0;
    long long now = 0;
    for (int i = 1; i <= n; ++i) {
        if (now + a[i].t > a[i].T) {
            if (a[i].t < pq.top()) {
                now -= pq.top() - a[i].t;
                pq.pop();
                pq.push(a[i].t);
            }
        } else {
            pq.push(a[i].t);
            now += a[i].t;
            ++ans;
        }
    }

    printf("%d\n", ans);
    return 0;
}