#include <bits/stdc++.h>
#define int long long
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
    if(flag) return x;
    return ~(x - 1);
}

const int maxn = 1e6 + 5;

char S[maxn];

int fail[maxn];

signed main() {
    int n = read();
    scanf("%s", S + 1);
    for (int i = 2, j = 0; i <= n; ++i) {
        while (j > 0 && S[j + 1] != S[i])
            j = fail[j];
        if (S[j + 1] == S[i])
            ++j;
        fail[i] = j;
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        int k = i;
        while (fail[k] != 0)
            k = fail[k];
        if (fail[i] != 0)
            fail[i] = k;
        ans += i - k;
    }

    printf("%lld\n", ans);
    return 0;
}