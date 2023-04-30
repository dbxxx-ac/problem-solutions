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

const std :: string t = "abacaba";

inline int get(std :: string s) {
    int res = 0, n = s.length();
    for (int i = 0; i < n - 6; ++i)
        if (s.substr(i, 7) == t)
            ++res;
    return res;
}

inline void out(std :: string s) {
    puts("Yes");
    for (char c : s)
        putchar(c == '?' ? 'd' : c);
    puts("");
}

int main() {
    int T = read();
    while (T--) {
        std :: string s;
        int n = read();
        std :: cin >> s;

        int res = get(s);
        
        if (res > 1) {
            puts("No");
            continue;
        } else if (res == 1) {
            out(s);
            continue;
        }

        bool fnd = false;
        for (int i = 0; i < n - 6; ++i) {
            bool fl = true;
            for (int j = 0; j < 7; ++j)
                if (s[i + j] != '?' && s[i + j] != t[j]) {
                    fl = false;
                    break;
                }
            
            if (fl) {
                std :: string st = s;
                st.replace(i, 7, t);
                if (get(st) == 1) {
                    out(st);
                    fnd = true;
                    break;
                }
            }
        }

        if (!fnd)
            puts("No");
    }

    return 0;
}