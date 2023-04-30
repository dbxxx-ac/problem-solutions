/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-11-19 10:14:42 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-11-19 23:25:28
 */
#include <bits/stdc++.h>

inline int read() {
	int x = 0;
	bool f = true;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar())
		if (ch == '-')
			f = false;
	for (; isdigit(ch); ch = getchar())
		x = (x << 1) + (x << 3) + ch - '0';
	return f ? x : (~(x - 1));
}
inline int lowbit(int x) {
	return x & (-x);
}
inline int min(int a, int b) {
	return a < b ? a : b;
}

const int maxn = (int)5e5 + 5;

struct Point {
	int x, y;
} a[maxn], b[maxn];

int c[maxn];

int n;
inline void add(int x) {
	for (; x <= n; x += lowbit(x))
		++c[x];
}

inline int get(int x) {
	int ans = 0;
	for (; x; x -= lowbit(x))
		ans += c[x];
	return ans;
}

inline void reset() {
	for (int i = 1; i <= n; ++i)
		c[i] = 0;
}

inline int solve(Point *a) {
	std :: sort(a + 1, a + 1 + n, [](Point x, Point y) {
		return x.x < y.x;
	});
	if (a[n >> 1].x != a[(n >> 1) + 1].x)
		return 2;

	if (n > 50)
		return 3;
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			int ans = 0;
			for (int k = 1; k <= n; ++k)
				if (a[k].x >= i && a[k].y <= j)
					++ans;
			if ((ans << 1) == n)
				return 3;
		}
	return 4;
	// std :: reverse(a + 1, a + 1 + n);
	
	// // for (int i = 1; i <= n; ++i)
	// // 	printf("%d ", c[i]);
	// // puts("");
	
	// for (int i = 1; i <= n; ++i) {
	// 	if (a[i].x != a[i - 1].x) {
	// 		add(a[i].y);
	// 		for (int j = i + 1; a[j].x == a[j - 1].x; ++j)
	// 			add(a[j].y);
	// 	}
		
	// 	int ans = get(a[i].y);

	// 	// printf("%d ", i);
	// 	// printf("%d %d %d\n", a[i].x, a[i].y, ans);
		
	// 	if ((ans << 1) == n) {
	// 		reset();
	// 		return 3;
	// 	}
	// }

	// reset();
	// return 4;
}

int main() {
	int T = read();
	for (int t = 1; t <= T; ++t) {
		n = read();
		for (int i = 1; i <= n; ++i) {
			int x = read(), y = read();
			a[i] = (Point){x, y};
			b[i] = (Point){y, x};
		}
		
		// if (t == 113)
		// 	for (int i = 1; i <= n; ++i)
		// 		printf("%d %d\n", a[i].x, a[i].y);


		// solve(a);
		// printf("%d\n", n);
		// solve(b);
		// puts("");
		printf("%d\n", min(solve(a), solve(b)));
	}

	return 0;
}