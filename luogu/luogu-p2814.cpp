/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-09-08 19:06:31 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-09-08 19:16:20
 */
#include <iostream>
#include <cstdio>
#include <map>
#include <string>

std :: map <std :: string, std :: string> fa;

std :: string find(std :: string x) {
    while (x != fa[x]) x = fa[x] = fa[fa[x]];
    return x;
}

int main() {
    char op;
    std :: cin >> op;
    std :: string recent;
    while (op != '$') {
        std :: string str;
        std :: cin >> str;
        if (op == '#') {
            recent = str;
            if (fa[str] == "") fa[str] = str;
        } else if (op == '+') {
            fa[str] = recent;
        } else if (op == '?') {
            std :: printf("%s %s\n", str.c_str(), find(str).c_str());
        }
        std :: cin >> op;
    }
    return 0;
}