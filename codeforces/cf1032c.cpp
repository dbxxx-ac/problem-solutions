/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-01-07 01:36:54 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-01-07 02:23:00
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

const int maxn = (int)1e5 + 5;

int a[maxn];
char b[maxn]; // b[i] 表示 b[i] 和 b[i + 1] 的大小关系

int main() {
    int n = read();
    if (n == 1) {
        puts("1");
        return 0;
    }
    
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i + 1])
            b[i] = '<';
        else if (a[i] > a[i + 1])
            b[i] = '>';
        else
            b[i] = '!';
    }
    
    int lst = 1;
    if (b[1] == '>')
        lst = 5;
    else if (b[1] == '!')
        lst = 2;
    
    std :: vector <int> ans = {lst};
    
    for (int i = 2; i < n; ++i) {
        int now;
        char p = b[i - 1], q = b[i];
        if (p == '<') {
            if (lst == 5)
                break;
            now = lst + 1;
            if (q == '>')
                now = 5;
        } else if (p == '>') {
            if (lst == 1)
                break;
            now = lst - 1;
            if (q == '<')
                now = 1;
        } else if (p == '!') {
            if (q == '!') {
                now = 3;
                if (lst == 3)
                    now = 2;
            } else if (q == '<') {
                now = 1;
                if (lst == 1)
                    now = 2;
            } else if (q == '>') {
                now = 5;
                if (lst == 5)
                    now = 4;
            }
        }

        ans.push_back(lst = now);
    }

    if (b[n - 1] == '<')
        ans.push_back(5);
    else if (b[n - 1] == '>')
        ans.push_back(1);
    else
        ans.push_back(lst == 5 ? 4 : 5);
    
    if ((int)ans.size() == n)
        for (int x : ans)
            printf("%d ", x);
    else
        printf("-1");
    puts("");
    return 0;
}