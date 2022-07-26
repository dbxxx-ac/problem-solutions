/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-07-19 23:19:35 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-07-20 00:33:19
 */
#include <iostream>
#include <cstdio>

void work(std :: string s1, std :: string s2) {
    if(s1.size() == 0) return ;
    char root = s2[0];
    int pos = s1.find(root);
    work(s1.substr(0, pos), s2.substr(1, pos));
    work(s1.substr(pos + 1), s2.substr(pos + 1));
    std :: cout << root;
}

int main() {
    std :: string s1, s2;
    std :: cin >> s1 >> s2;
    work(s1, s2);
    return 0;
}