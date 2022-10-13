/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-09-24 10:15:37 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-09-24 12:11:10
 */
#include <bits/stdc++.h>
inline int read() {
	int x = 0;
	bool flag = true;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-')
			flag = false;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	if(flag)
		return x;
	return ~(x - 1);
}

const int maxn = 12 * 60 + 105;

int f[maxn];

int main() {
	for (int h = 0; h < 12; ++h) {
		for (int m = 10; m < 60; ++m) {
			int x = h * 60 + m;
			int a = h / 10, b = h % 10, c = m / 10, d = m % 10;
			if (h == 0) {
				a = 1;
				b = 2;
			}
			if (a == 0)
				a = 2 * b - c;
			// if (x == 154)
				// printf("%d %d %d %d\n", a, b, c, d);
				
			if (d - c == c - b && c - b == b - a)
				f[x] = 1;
		}
	}

	for (int i = 0; i <= 11 * 60 + 59; ++i)
		f[i] += f[i - 1];

	int d = read();
	const int g = 12 * 60;
	while (d--) {
		int t = read();
		int k = t / g, p = t % g;
		printf("%d\n", k * f[g - 1] + f[p]);
	}
	
	return 0;
}