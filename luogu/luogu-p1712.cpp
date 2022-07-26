/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-03-25 23:20:07 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-03-26 00:03:35
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

const int maxn = 500005;
const int inf = 0x3f3f3f3f;

struct segment {
	int l, r, len;
	void set(int l, int r) {
		this -> l = l;
		this -> r = r;
		this -> len = r - l;
	}
	const bool operator < (const segment b) {
		return this -> len < b.len;
	}
}a[maxn];

int u[maxn * 2];

int d[maxn << 3], t[maxn << 3];

inline int lson(int x) {
	return x << 1;
}

inline int rson(int x) {
	return x << 1 | 1;
}

inline void update(int x, int v) {
	d[x] += v;
	t[x] += v;
	return ;
}

inline void pushdown(int x) {
	if (t[x]) {
		update(lson(x), t[x]);
		update(rson(x), t[x]);
		t[x] = 0;
	}
	return ;
}

inline void modify(int x, int l, int r, int L, int R, int v) {
	if (L > r || R < l)
		return ;
	if (L <= l && R >= r) {
		update(x, v);
		return ;
	}
	pushdown(x);
	int mid = l + r >> 1;
	if (L <= mid)
		modify(lson(x), l, mid, L, R, v);
	if (R > mid)
		modify(rson(x), mid + 1, r, L, R, v);
	d[x] = std :: max(d[lson(x)], d[rson(x)]);
}

int main() {
	int n = read(), m = read(), num = 0;
	for (int i = 1; i <= n; ++i) {
		int l = read(), r = read();
		a[i].set(l, r);
		u[++num] = l;
		u[++num] = r;
	}

	std :: sort(a + 1, a + 1 + n);
	std :: sort(u + 1, u + 1 + num);
	num = std :: unique(u + 1, u + 1 + num) - u - 1;
	
	for (int i = 1; i <= n; ++i) {
		a[i].l = std :: lower_bound(u + 1, u + 1 + num, a[i].l) - u;
		a[i].r = std :: lower_bound(u + 1, u + 1 + num, a[i].r) - u;
	}

	int ans = inf;
	for (int i = 1, j = 1; i <= n; ++i) {
		modify(1, 1, num, a[i].l, a[i].r, 1);
		while(d[1] >= m) {
			ans = std :: min(ans, a[i].len - a[j].len);
			modify(1 ,1, num, a[j].l, a[j].r, -1);
			++j;
		}
	}

	if (ans == inf)
		ans = -1;
	printf("%d\n", ans);
	return 0;
}

