/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-06-26 18:33:01 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-06-26 18:36:51
 */
#include <iostream>
#include <cstdio>

const int maxn = 45;
int a[maxn][maxn];

int main() {
	int n;
	std :: cin >> n;
	int lastx = 1, lasty = 1 + n >> 1;

	for (int i = 1; i <= n * n; ++i) {
		a[lastx][lasty] = i;
		if (i == n * n) break;
		int nxtx = (lastx + n - 2) % n + 1;
		int nxty = lasty % n + 1;
		if (a[nxtx][nxty] == 0) {
			lastx = nxtx;
			lasty = nxty;
		} else {
			lastx %= n;
			lastx++;
		}
	}

	for (int i = 1; i <= n; ++i, puts(""))
		for (int j = 1; j <= n; ++j, putchar(' '))
			std :: cout << a[i][j];
	
	return 0;
}