/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-03 11:23:00 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-03 16:14:34
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>

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
	if(flag) return x;
	return ~(x - 1);
}

const int maxn = 50005;
const int mininf = INT_MIN / 3;

struct cow {
	int w, s;
}a[maxn];

inline int max(int a, int b) {
	return a > b ? a : b;
}

bool cmp(cow a, cow b) {
	return a.w + a.s < b.w + b.s;
}

int main() {
	int n = read();
	for (int i = 1; i <= n; ++i) {
		a[i].w = read();
		a[i].s = read();
	}

	std :: sort(a + 1, a + 1 + n, cmp);
	int sum = 0, ans = mininf;

	for (int i = 1; i <= n; ++i) {
		ans = max(ans, sum - a[i].s);
		sum += a[i].w;
	}

	printf("%d\n", ans);
	return 0;
}