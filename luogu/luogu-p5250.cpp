/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-08-17 18:25:55 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-08-17 18:28:14
 */
#include <iostream>
#include <cstdio>
#include <map>

int main() {
    std :: map <int, bool> store;
    int n;
    std :: scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        int op, len;
        std :: scanf("%d%d", &op, &len);

        if (op == 1) {
            if (store[len]) std :: printf("Already Exist\n");
            else store[len] = true;
        } else {
            if (store.empty()) std :: printf("Empty\n");
            else if (store[len]) {
                store.erase(len);
                std :: printf("%d\n", len);
            } else {
                store[len] = true;
                std :: map <int, bool> :: iterator iter = store.find(len);
                std :: map <int, bool> :: iterator iter2 = iter;
                ++iter2;
                if (iter == store.begin()) {
                    std :: printf("%d\n", iter2 -> first);
                    store.erase(iter2);
                } else if (iter2 == store.end()) {
                    std :: printf("%d\n", (--iter) -> first);
                    store.erase(iter);
                } else if (len - (--iter) -> first <= iter2 -> first - len) {
                    std :: printf("%d\n", iter -> first);
                    store.erase(iter);
                } else {
                    std :: printf("%d\n", iter2 -> first);
                    store.erase(iter2);
                }
                store.erase(len);
            }
        }
    }

    return 0;
}