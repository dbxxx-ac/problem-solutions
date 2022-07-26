/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-11-24 00:12:55 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-11-25 19:03:13
 */
#include <bits/stdc++.h>
inline int read() {
    int x = 0;
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

const int maxn = 65;
int a[maxn], nxtdif[maxn];
int cnt = 0;
bool vis[maxn];

int n;

void dfs(int tot, int num, int remain, int l, int target) {
    if (remain == 0) {
        if (tot == target) {
            std :: printf("%d\n", l);
            exit(0);
        }
        for (int i = 1; i <= cnt; ++i)
            if (!vis[i]) {
                vis[i] = true;
                dfs(tot + 1, i, l - a[i], l, target);
                vis[i] = false;
                break;
            }
    }
    
    int start = std :: lower_bound(a + num, a + 1 + cnt, remain, std :: greater <int> ()) - a;
    for (int i = start; i <= cnt; ) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(tot, i, remain - a[i], l, target);
            vis[i] = false;
            
            if (remain == a[i] || remain == l)
                return ;
            i = nxtdif[i];
        } else
            ++i;
    }
}

int main() {
    int sum = 0;
    n = read();
    for (int i = 1; i <= n; ++i) {
        int x = read();
        if (x <= 50) {
            a[++cnt] = x;
            sum += x;
        }
    }

    std :: sort(a + 1, a + 1 + cnt, std :: greater <int> ());
    nxtdif[cnt] = cnt + 1;
    for (int i = cnt - 1; i; --i)
        if (a[i] == a[i + 1])
            nxtdif[i] = nxtdif[i + 1];
        else
            nxtdif[i] = i + 1;
    
    for (int i = a[1]; i <= sum / 2; ++i) {
        if (sum % i == 0) {
            vis[1] = true;
            dfs(1, 1, i - a[1], i, sum / i);
            vis[1] = false;
        }
    }

    std :: printf("%d\n", sum);//只能拼出一根。。
    return 0;
}