/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-05-02 23:53:02 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-05-03 00:44:21
 */
#include <iostream>
#include <cstdio>
#include <string>

int main() {
    std :: string num;
    int k;
    std :: cin >> num >> k;
    while(k--) {
        bool flag = false;
        for(int i = 0; i < num.length() - 1; i++)
            if(num[i] > num[i + 1]) {
                num.erase(i, 1);
                flag = true;
                break;
            }
        if(!flag) num.erase(num.length() - 1, 1);
    }
    num.erase(0, num.find_first_not_of("0"));
    if(num == "") num = "0";
    std :: cout << num << std :: endl;
    return 0;
}