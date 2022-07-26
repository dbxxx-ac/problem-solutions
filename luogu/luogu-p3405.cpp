/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-08-17 18:14:48 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-08-17 18:23:15
 */
#include <iostream>
#include <cstdio>

const int maxl = 30 * 30 + 5;
int a[maxl][maxl];

int getnum(std :: string str) {
    return (str[0] - 'A' + 1) * 26 + str[1] - 'A' + 1;
}

int main() {
    int n;
    long long ans = 0;
    std :: scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        std :: string city, state;
        std :: cin >> city >> state;
        int citynum = getnum(city);
        int statenum = getnum(state);
        if (citynum != statenum) {
            ++a[citynum][statenum];
            ans += a[statenum][citynum];
        }
    }

    std :: printf("%lld\n", ans);
    return 0;
}