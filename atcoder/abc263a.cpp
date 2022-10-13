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

const int maxn = 7;

int a[maxn];

int main() {
    for (int i = 1; i <= 5; ++i)
        a[i] = read();
    std :: sort(a + 1, a + 6);
    if (a[1] == a[2] && a[3] == a[4] && a[4] == a[5]) {
        puts("Yes");
        return 0;
    }
    if (a[1] == a[2] && a[2] == a[3] && a[4] == a[5]) {
        puts("Yes");
        return 0;
    }
    puts("No");
    return 0;
}