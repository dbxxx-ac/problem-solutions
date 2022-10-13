/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-09-04 20:22:50 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-09-04 21:55:37
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

const int maxn = 405;
int a[maxn];

std :: vector <std :: pair <char, int> > ans;

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
    }
    
    for (int i = 1; i <= n; ++i) {
        int x = 0, y = 0;
        for (int j = 2; j <= n; j += 2) {
            if (a[j] & 1) {
                x = j;
                break;
            }
        }
        if (x == 0)
            break;
        for (int j = 1; j <= n; j += 2) {
            if ((a[j] & 1) == 0) {
                y = j;
                break;
            }
        }

        if (x > y)
            x ^= y ^= x ^= y;
        
        while (y - x > 1) {
            ans.emplace_back('B', x);
            a[x] ^= a[x + 2] ^= a[x] ^= a[x + 2];
            x += 2;
        }

        ans.emplace_back('A', x);
        a[x] ^= a[x + 1] ^= a[x] ^= a[x + 1];
    }


    for (int i = 1; i < n; ++i) {
        for (int j = 1; j + 2 <= n; j += 2) {
            if (a[j + 2] < a[j]) {
                ans.emplace_back('B', j);
                a[j] ^= a[j + 2] ^= a[j] ^= a[j + 2];
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 2; j + 2 <= n; j += 2) {
            if (a[j + 2] < a[j]) {
                ans.emplace_back('B', j);
                a[j] ^= a[j + 2] ^= a[j] ^= a[j + 2];
            }
        }
    }

    std :: cout << ans.size() << std :: endl;

    for (auto v : ans) {
        printf("%c %d\n", v.first, v.second);
    }
    
    return 0;
}

/*
2 4 3 1 5
3 4 2 1 5
3 4 1 2 5
1 4 3 2 5
*/