/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-04-26 09:50:00 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-04-26 10:01:05
 */
#include <iostream>
#include <cstdio>
#include <string>

std :: string s;
long long n;

int main() {
    std :: cin >> s >> n;
    s = ' ' + s;
    int len = s.length()  - 1;
    while(len < n) {
        long long mid = len;
        while(mid * 2 < n) mid <<= 1;
        n -= (mid + 1);
        if(n == 0) n = mid;
    }
    std :: cout << s[n] << std :: endl;
    return 0;
}
