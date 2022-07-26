/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-18 15:37:23 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-18 19:20:27
 */
#include <bits/stdc++.h>
#define int long long

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

const int maxn = 3e6 + 5;
int inv[maxn];

signed main() {
	int n = read(), p = read();
	inv[1] = 1;
	puts("1");
	
	for (int i = 2; i <= n; ++i) {
		inv[i] = (p - p / i) * inv[p % i] % p;
		printf("%lld\n", inv[i]);
	}

	return 0;
}