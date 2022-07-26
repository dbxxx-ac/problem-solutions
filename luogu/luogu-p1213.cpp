/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-03 16:16:05 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-03 18:05:03
 */
#include <bits/stdc++.h>
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

const int d[9][5] = {
    {1, 2, 4, 5, 0},
    {1, 2, 3, 0, 0},
    {2, 3, 5, 6, 0},
    {1, 4, 7, 0, 0},
    {2, 4, 5, 6, 8},
    {3, 6, 9, 0, 0},
    {4, 5, 7, 8, 0},
    {7, 8, 9, 0, 0},
    {5, 6, 8, 9, 0}
};

std :: basic_string <int> sol;

int main() {
    int state = 0;
    for (int i = 0; i < 9; ++i) {
        int x = read() / 3 & 3; // 3 6 9 12 -> 1 2 3 0 -> 01 10 11 00
        state |= x << (i << 1); 
    }
    printf("%d\n", state);

    for (int i = 0; i < 1 << 19; ++i) {
        int now = state;
        for (int j = 0; j < 9; ++j) {
            int t = (i >> (j << 1)) & 3;
            if (t == 0)
                continue; // 优化
            for (int k = 0; k < 5; ++k) {
                //printf("%d\n", _);
                if (d[j][k] == 0)
                    break;
                int p = (d[j][k] - 1) << 1; // p 代表钟表所在的后一位
                for (int _ = 0; _ < t; ++_) {
                    if (now & (1 << p)) // 如果后一位是1
                        now ^= 1 << (p | 1); // 反转前一位
                    now ^= 1 << p; // 无论如何都要反转后一位
                }
            }
        }
        if (now == 0) {
            std :: basic_string <int> now_sol;
            now_sol.clear();
            for (int j = 0; j < 9; ++j)
                for (int _ = 0; _ < ((i >> (j << 1)) & 3); ++_) // 意义同上
                    now_sol += j + 1;
            if (sol.empty() || now_sol.size() < sol.size())
                sol = now_sol;
            break;
        }
    }
    
    for (int i = 0; i < sol.size(); ++i)
        printf("%d ", sol[i]);
    puts("");
    return 0;
}

/*
9 9 12
6 6 6
6 3 6 
*/