/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-09-23 21:02:08 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-09-23 22:35:56
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

const int maxn = 75;
const int maxm = maxn * 35;

int f[2][maxm][maxm];

struct node {
	int h, t;
}a[maxn];

inline bool getmin(int &a, int b) {
	return b < a ? a = b, true : false;
}

inline bool getmin(long long &a, long long b) {
	return b < a ? a = b, true : false;
}

int main() {
	int n = read(); 
	for (int i = 1; i <= n; ++i) {
		int h = read(), t = read();
		a[i] = (node){h, t};
	}

	std :: sort(a + 1, a + 1 + n, [](node b, node c) {
		return b.h > c.h;
	});
	
	std :: memset(f[0], 0x3f, sizeof(f[0]));
	f[0][0][0] = 0;

	int x = 0;
	for (int u = 1; u <= n; x += a[u].t, ++u) {
		int i = u & 1, t = a[u].t, h = a[u].h;
		std :: memset(f[i], 0x3f, sizeof(f[i]));
		for (int j = 0; j <= x; ++j) {
			for (int k = 0; k <= x - j; ++k) {
				int p = f[i ^ 1][j][k];
				getmin(f[i][j + t][k], p + (j ? 0 : h));
				getmin(f[i][j][k + t], p + (k ? 0 : h));
				int l = x - j - k;
				getmin(f[i][j][k], p + (l ? 0 : h));
			}
		}
	}

	long long ans = LONG_LONG_MAX;
	for (int i = 1; i < x; ++i)
		for (int j = 1; j < x - i; ++j)
			getmin(ans, 1LL * std :: max({i, j, x - i - j}) * f[n & 1][i][j]);
	
	printf("%lld\n", ans);
	return 0;
}