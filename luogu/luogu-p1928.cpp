/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-04-13 23:56:00 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-04-13 23:59:07
 */
#include <iostream>
#include <cstdio>
#include <string>

std :: string work() {
    std :: string ret = "";
    char ch;
    while(std :: cin >> ch) {
        if(ch == '[') {
            int times;
            std :: cin >> times;
            std :: string repeat = work();
            while(times--) ret += repeat;
        } else if(ch == ']') {
            return ret;
        } else ret += ch;
    }    
}

int main() {
    std :: string ans = work();
    std :: cout << ans << std :: endl;
    return 0;
}