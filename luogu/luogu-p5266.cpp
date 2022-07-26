/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-08-18 10:17:49 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-08-18 10:34:17
 */
#include <iostream>
#include <cstdio>
#include <string>
#include <map>

int main() {
    std :: map <std :: string, int> a;
    int n;
    std :: scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int op;
        std :: string name;
        std :: scanf("%d", &op);
        if (op == 1) {
            int score;
            std :: cin >> name >> score;
            a[name] = score;
            if (true) std :: printf("OK\n");
            else std :: printf("DBXXX AK IOI\n");
        } else if (op == 2) {
            std :: cin >> name;
            if (a.count(name)) {
                std :: printf("%d\n", a[name]);
            } else
                std :: printf("Not found\n");
        } else if (op == 3) {
            std :: cin >> name;
            if (a.count(name)) {
                a.erase(name);
                std :: printf("Deleted successfully\n");
            } else 
                std :: printf("Not found\n");
        } else if (op == 4) {
            std :: printf("%d\n", a.size());
        } else {
            std :: printf("Invalid operation\n");//NO WAY IN THIS CASE!
            //JUST PI YI XIA (foggy)
        }
    }
    return 0;
}