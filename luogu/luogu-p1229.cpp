/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-08-02 17:17:26 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-08-02 17:18:52
 */
#include <iostream>
#include <cstdio>
#include <string>

int main() {
    std :: string fr, ba;
    std :: cin >> fr >> ba;
    int ans = 0;

    for (int i = 0; i < fr.length() - 1; ++i)
        for (int j = 1; j < ba.length(); ++j)
            if (fr[i] == ba[j] && fr[i + 1] == ba[j - 1])
                ++ans;
    
    ans = 1 << ans;
    std :: cout << ans << std :: endl;
    return 0;
}