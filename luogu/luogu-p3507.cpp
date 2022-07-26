/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-04-06 23:23:22 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-04-06 23:30:39
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

inline int read() {
	int x = 0;
	bool flag = true;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			flag = false;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	if (flag)
		return x;
	return ~(x - 1);
}

const int maxn = 1000005;
int a[maxn], f[maxn];

int main() {
	int n = read();
	for (int i = 1; i <= n; ++i)
		a[i] = read();
	std :: sort(a + 1, a + 1 + n);

	f[1] = a[1];
	for (int i = 2; i <= n; ++i)
		f[i] = std :: max(f[i - 1], a[i] - f[i - 1]);
	
	printf("%d\n", f[n]);
	return 0;
}