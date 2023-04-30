/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-03-29 17:41:29 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-03-29 19:02:57
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

inline std :: string construct(std :: string l, std :: string r, char dl, char dr) {
    std :: string ans;
    int i;
    for (i = 0; i < l.length(); ++i) {
        if (l[i] == r[i]) {
            if (l[i] < dl || l[i] > dr)
                return "X";
            else
                ans.push_back(l[i]);
        } else
            break;
    }
    for (; i < l.length(); ++i) {
        if (l[i] + 1 <= r[i] - 1 && dr >= l[i] + 1 && dl <= r[i] - 1) {
            // find [dl, dr] X [l[i] + 1, r[i] - 1]
            ans.push_back(std :: max(dl, char(l[i] + 1)));
            for (++i; i < l.length(); ++i)
                ans.push_back(dl);
            return ans;
        }

        if (l[i] >= dl && l[i] <= dr) {
            ans.push_back(dl);
        } else {
            
        }
    }
}

inline std :: string solve(std :: string l, std :: string r) {
    std :: string ans;
    if (r.length() > l.length()) {
        for (int i = 1; i <= l.length(); ++i)
            ans.push_back('9');
        return ans;
    }

    for (int D = 0; D <= 9; ++D)
        for (int d = 0; d <= 9 - D; ++d) {
            ans = construct(l, r, d + '0', d + D + '0');
            if (ans != "X")
                return ans;
        }
}

int main() {
    int T = read();
    while (T--) {
        std :: string l, r;
        std :: cin >> l >> r;
        std :: cout << solve(l, r) << std :: endl;
    }
    return 0;
}