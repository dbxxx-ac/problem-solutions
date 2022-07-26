/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-06-13 09:31:12 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-06-13 10:27:08
 */
#include <iostream>
#include <cstdio>

const int maxn = 1e6+5;

int a[maxn];

int my_lower_bound(int fnd_array[], int size, int q) {
    int l = 1;
    int r = size;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (fnd_array[mid] >= q) r = mid;
        else l = mid + 1;
    }
    return a[l] == q ? l : -1;
}

inline int read() {
    int x;
    std :: cin >> x;
    return x;
}

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= n; ++i) 
        a[i] = read();
    
    for (int i = 1; i <= m; i++) {
        int q = read();
        std :: cout << my_lower_bound(a, n, q) << ' ';
    }

    return 0;
}