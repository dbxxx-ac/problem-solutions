/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-07-10 08:53:08 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-07-10 10:02:50
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>
#include <set>

std :: set <int> a;

int main() {
    a.insert(INT_MAX / 4);
    a.insert(INT_MIN / 4);//学到了还能这么写Orz，题解太强了

    int n, ans = 0;
    std :: cin >> n;
    for (int i = 1; i <= n; ++i) {
        int money;
        std :: cin >> money;

        if (a.size() == 2) {
            ans += money;
        } else {
            std :: set <int> :: iterator x = a.lower_bound(money);
            if (*x == money) continue;
            std :: set <int> :: iterator y = x; y--;
            ans += std :: min(std :: abs(money - *x), std :: abs(money - *y));
        }
        a.insert(money);
    }

    std :: cout << ans << std :: endl;
    return 0;
}