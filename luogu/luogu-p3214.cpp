/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-04-22 23:37:20 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-04-23 00:22:39
 */
#include <iostream>
#include <cstdio>

#define int long long // 好习惯，此处 % 葵 %%%%%%%
//但是这样我真的很烦你知道吗？int所有高亮都变成了紫色，跟 #include 一样
//无语
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

const int mod = 1e8 + 7;

inline int pow(int a, int b = mod - 2) {
	int s = 1;
	for (; b; b >>= 1, (a *= a) %= mod)
		if (b & 1)
			(s *= a) %= mod;
	return s;
}

signed main() {
	int n = read(), m = read();
	int S = pow(2, n) - 1;
	int C = S * (S - 1) % mod * pow(2) % mod;
	if (m <= 2) {
		puts("0");
		return 0;
	}
	int f = 0, g = 0, h = 0;
	for (int i = 3; i <= m; ++i) {
		f = (C - g - h * (S - i + 2 + mod) % mod + mod) % mod * pow(i) % mod;
		(C *= (S - i + 1 + mod) * pow(i) % mod) %= mod;
		h = g;
		g = f;
	}
	printf("%lld\n", f);
	return 0;
}