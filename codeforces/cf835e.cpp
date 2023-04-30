/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-12-19 22:20:46 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-12-19 22:41:16
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

int n, x, y;

inline int ask(int S) {
    std :: vector <int> vec;
    for (int i = 1; i <= n; ++i)
        if ((i & S) == S)
            vec.push_back(i);
    
    if (vec.empty())
        return 0;
    
    printf("? %d ", (int)vec.size());
    for (int v : vec)
        printf("%d ", v);
    puts("");
    fflush(stdout);

    int ans = read();
    return (ans == y || ans == (x ^ y)) ? 1 : 0;
}

int t[15];

int main() {
    n = read();
    x = read();
    y = read();

    int k = 0;
    int x = 0;
    
    for (int i = 0; i < 10; ++i) {
        t[i] = (1 << i);
        int ans = ask(t[i]);
        if (ans) {
            k = i;
            x |= t[i];
        }
    }

    int a = t[k];
    
    for (int i = 0; i < 10; ++i) if (i ^ k) {
        if (ask(t[i] | t[k]))
            a |= t[i];
    }
    
    int b = (a ^ x);
    if (a > b)
        a ^= b ^= a ^= b;
    
    printf("! %d %d\n", a, b);
    return 0;
}