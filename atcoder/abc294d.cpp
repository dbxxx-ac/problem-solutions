/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-19 20:19:59 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-19 20:36:49
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

std :: queue <int> q1, q2;
std :: priority_queue <int, std :: vector <int>, std :: greater <int> > q3;
// q1 : not been called
// q2 : called but not come
// q3 : called and come, but in q2

bool check() {
    if (q3.empty() || q2.empty())
        return false;
    return q3.top() == q2.front();
}

int main() {
    int n = read(), q = read();
    for (int i = 1; i <= n; ++i)
        q1.push(i);
    
    while (q--) {
        int op = read();
        if (op == 1) {
            int x = q1.front();
            q1.pop();
            q2.push(x);
        } else if (op == 2) {
            int x = read();
            q3.push(x);
        } else if (op == 3) {
            while (check()) {
                q2.pop();
                q3.pop();
            }
            int x = q2.front();
            printf("%d\n", x);
        }
    }
    return 0;
}