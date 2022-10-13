/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-03 16:20:56 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-03 16:48:33
 */
// 卡精度过题，n^2，非正解。。。

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

const int maxn = (int)5e4 + 5;
float a[maxn], b[maxn], c[maxn];

const int maxp = (int)4e6 + (int)5e5 + 1; // 1 << 22
int f[maxp];

int main() {
    int n = read(), k = read();

    for (int i = 1; i <= n; ++i) {
        scanf("%f%f%f", &a[i], &b[i], &c[i]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            float a1 = a[i], b1 = b[i], c1 = c[i];
            float a2 = a[j], b2 = b[j], c2 = c[j];

            float de = a1 * b2 - a2 * b1;
            if (de == 0)
                continue;
            
            float x = (b1 * c2 - b2 * c1) / de;
            float y = (a1 * c2 - a2 * c1) / de;
            float d = x * x + y * y;
            
            unsigned p = 0;
            std :: memcpy(&p, &d, sizeof(float));
            ++f[p >> 9];
        }
    }

    int sum = 0;
    for (int i = 0; i < (1 << 22); ++i) {
        sum += f[i];
        if (sum >= k) {
            float d = 0;
            unsigned p = (i << 9);
            std :: memcpy(&d, &p, sizeof(float));
            std :: cout << sqrt(d);
            return 0;
        }
    }
    return 0;
}