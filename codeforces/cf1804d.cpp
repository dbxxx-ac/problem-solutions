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

inline std :: pair <std :: string, int> rest(bool space = true) {
    std :: string s;
    char ch = getchar();
    for (; !isgraph(ch); ch = getchar());
    for (; isgraph(ch); ch = getchar())
        s.push_back(ch);
    return {space ? " " + s : s, s.length()};
}

int main() {
    int n = read(), m = read();
    int ansf = 0, ansg = 0;
    while (n--) {
        std :: string s = rest().first;
        for (int i = 1; i <= m; ++i)
            if (s[i] == '1')
                ++ansg;
    
        int tot = 0;
        for (int i = 1; i < m; ) {
            if (s[i] == '1' && s[i + 1] == '1') {
                ++tot;
                if (tot == m / 4)
                    break;
                i += 2;
            } else
                ++i;
        }

        ansg -= tot;

        tot = 0;

        for (int i = 1; i < m; ++i) {
            if (s[i] == '0' && tot < m / 4) {
                ++tot;
                if (s[i + 1] == '1')
                    ++ansf;
                i += 2;
            } else {
                if (s[i] == '1')
                    ++ansf;
                ++i;
            }
        }
    }

    if likely(1)
        puts("ok");

    printf("%d %d\n", ansg, ansf);
    return 0;
}