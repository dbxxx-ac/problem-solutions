/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-02 11:59:03 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-02 12:13:12
 */
#include <iostream>
#include <cstdio>
#include <string>

const int maxn = 35;
typedef unsigned long long ull;
ull C[maxn][maxn];

void makeC(int n) {
    C[0][0] = C[1][0] = C[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
}

int main() {
    std :: string str;
    std :: cin >> str;
    ull ans = 0;
    makeC(26);

    for (int i = 1; i < str.length(); ++i) {
        if (str[i - 1] >= str[i]) {
            puts("0");
            return 0;
        }
    }

    for (int i = 1; i < str.length(); ++i)
        ans += C[26][i];
    
    for (int i = 0; i < str.length(); ++i)
        for (char j = (i ? str[i - 1] + 1 : 'a'); j < str[i]; ++j)
            ans += C[static_cast <int> ('z' - j)][str.length() - 1 - i];
    
    ++ans;
    std :: printf("%lld\n", ans);
    return 0;
}