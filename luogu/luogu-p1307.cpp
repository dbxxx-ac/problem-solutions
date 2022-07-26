/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-06-20 08:54:10 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-06-20 10:18:44
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

int main() {
    std :: string s, ans;
    std :: cin >> s;
    int startidx = 0, endidx = s.length() - 1;
    if (s[0] == '-') {
        putc('-', stdout);
        startidx = 1;
    }
    while (s[endidx] == '0' && endidx - startidx) endidx--;
    for (int i = endidx; i >= startidx; i--) putc(s[i], stdout);
    return 0;
}