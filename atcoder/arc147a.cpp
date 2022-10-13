/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-09-04 20:02:50 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-09-04 20:14:48
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

int main() {
    std :: priority_queue <int> maxq;
    std :: priority_queue <int, std :: vector <int>, std :: greater <int> > minq, delq;
    
    int n = read();
    for (int i = 1; i <= n; ++i) {
        int x = read();
        maxq.push(x);
        minq.push(x);
    }

    int ans = 0;
    for (; maxq.size() != 1; ++ans) {
        int x = maxq.top();
        while (!delq.empty() && minq.top() == delq.top()) {
            minq.pop();
            delq.pop();
        }
        int y = minq.top();
        int p = x % y;
        maxq.pop();
        delq.push(x);
        if (p != 0) {
            maxq.push(p);
            minq.push(p);
        }
    }

    printf("%d\n", ans);
    return 0;
}