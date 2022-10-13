/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-09 20:13:25 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-09 20:32:34
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

const int maxn = (int)3e5 + 5;

char s[maxn];

int main() {
    int T = read();
    while (T--) {
        int n = read(), k = read();
        scanf("%s", s + 1);
        int l = 1, r = n;
        for (; l <= n; ++l)
            if (s[l] == '1')
                break;
        for (; r >= l; --r)
            if (s[r] == '1')
                break;
        
        if (l != n + 1) {
            int len = r - l + 1;
            for (int i = l; i <= r; ++i)
                if (s[i] == '0') {
                    puts("No");
                    continue;
                }
            
            if (len >= k) {
                puts(len == k ? "Yes" : "No");
                continue;
            }

            len = k - len; // 剩下的需要补齐的

            int ml = 0, mr = 0;
            for (int i = l - 1; i >= 1 && s[i] != '0'; --i, ++ml);
            for (int i = r + 1; i <= n && s[i] != '0'; ++i, ++mr);
            
            if (ml + mr <= len) {
                puts(ml + mr == len ? "Yes" : "No");
                continue;
            }

            puts((ml == 0 || mr == 0) ? "Yes" : "No");
        } else {
            int fl = 0;
            
            s[n + 1] = '0';
            for (int i = 1, lst = 1; i <= n + 1; ++i) {
                if (s[i] == '0') {
                    if (i - lst == k)
                        ++fl;
                    if (i - lst > k)
                        fl = 2;
                    lst = i + 1;
                }
            }

            puts(fl == 1 ? "Yes" : "No");
        }
    }
    return 0;
}