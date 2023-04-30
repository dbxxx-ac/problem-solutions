/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-10-22 20:03:06 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-10-22 20:05:35
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

const int maxw = 1005;
int a[maxw];
char s[maxw];

int main() {
    int h = read(), w = read();
    while (h--) {
        scanf("%s", s + 1);
        for (int i = 1; i <= w; ++i)
            if (s[i] == '#')
                ++a[i];
    }

    for (int i = 1; i <= w; ++i)
        printf("%d ", a[i]);
    
    puts("");
    return 0;
}