/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-03-09 00:02:34 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-03-09 23:03:48
 */
#include <iostream>
#include <cstdio>

void work(std :: string s1, std :: string s2) {
    if(s1.size() == 0) return ;
    char root = s2[s2.length() - 1];
    std :: cout << root;
    int pos = s1.find(root);
    work(s1.substr(0, pos), s2.substr(0, pos));
    work(s1.substr(pos + 1), s2.substr(pos, s1.size() - pos - 1));
}

int main() {
    std :: string s1, s2;
    std :: cin >> s1 >> s2;
    work(s1, s2);
    return 0;
}