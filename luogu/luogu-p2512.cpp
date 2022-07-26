#include <bits/stdc++.h>
#define int long long

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

const int maxn = 1e6 + 5;
int a[maxn], d[maxn];

int abs(int x) {
	return x > 0 ? x : -x;
}

signed main() {
	int n = read(), m = 0LL;
	for (int i = 1LL; i <= n; ++i) {
		a[i] = read();
		m += a[i];
	}
	m /= n;
	for (int i = 1LL; i <= n; ++i)
		d[i] = d[i - 1] + a[i] - m;
	int s = n + 1 >> 1;
	std :: nth_element(d + 1, d + s, d + n + 1);
	int ans = 0LL;
	for (int i = 1LL; i <= n; ++i)
		ans += abs(d[s] - d[i]);
	printf("%lld\n", ans);
	return 0;
}
