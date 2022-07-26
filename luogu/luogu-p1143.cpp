/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-01 12:00:26 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-01 12:24:04
 */
#include <iostream>
#include <cstdio>
#include <string>

int cti(char x) {
    if (x >= 'A') return x - 'A' + 10;
    return x - '0';
}

char itc(int x) {
    if (x >= 10) return x - 10 + 'A';
    return x + '0';
}

int main() {
    int n, m;
    long long x = 0;
    std :: string num, res = "";
    std :: cin >> n >> num >> m;
    for (int i = num.length() - 1, base = 1; i >= 0; --i, base *= n)
        x += cti(num[i]) * base;
    for (; x ; x /= m)
        res = itc(x % m) + res;
    std :: cout << res << std :: endl;
    return 0;
}