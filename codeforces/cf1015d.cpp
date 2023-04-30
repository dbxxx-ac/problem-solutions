/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-14 03:00:45 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-14 03:14:54
 */
#include <bits/stdc++.h>

#define int long long

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

signed main() {
    int n = read(), k = read(), s = read();

    if (s < k || s > (n - 1) * k) {
        puts("NO");
        return 0;
    }

    puts("YES");
    int p = s / k + 1, q = s % k;

    if (q & 1) {
        for (int i = 1; i <= k; ++i, putchar(' ')) {
            if (i & 1)
                printf("%lld", p + 1);
            else if (i < q)
                putchar('1');
            else
                putchar('2');
        }
    } else {
        for (int i = 1; i <= k; ++i, putchar(' ')) {
            if (i & 1) {
                if (i < q)
                    printf("%lld", p + 1);
                else
                    printf("%lld", p);
            } else
                putchar('1');
        }
    }
    return 0;
}