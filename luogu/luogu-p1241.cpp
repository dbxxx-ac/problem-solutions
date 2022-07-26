/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-07-09 23:50:33 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-07-10 00:06:07
 */
#include <iostream>
#include <cstdio>
#include <string>

const int maxs = 105;

bool paired[maxs];

int main() {
    std :: string s;
    std :: cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ')') {
            for (int j = i - 1; j >= 0; --j) {
                if (s[j] == '(' && !paired[j]) {
                    paired[i] = paired[j] = true;
                    break;
                }
                else if (s[j] == '[' && !paired[j]) break;
            }
        }

        if (s[i] == ']') {
            for (int j = i - 1; j >= 0; --j) {
                if (s[j] == '[' && !paired[j]) {
                    paired[i] = paired[j] = true;
                    break;
                }
                else if (s[j] == '(' && !paired[j]) break;
            }
        }
    }

    for (int i = 0; i < s.length(); ++i) {
        if (paired[i]) std :: cout << s[i];
        else {
            if (s[i] == '(' || s[i] == ')') std :: cout << "()";
            else std :: cout << "[]";
        }
    }

    return 0;
}