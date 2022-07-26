/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-02-27 20:49:14 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-02-27 22:25:20
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

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
	if (flag)
		return x;
	return ~(x - 1);
}

const int maxn = 300005;
const int maxm = 300005;

int n, m;

inline int lowbit(int x) {
	return x & -x;
}

struct number {
	int v, pos;
	const bool operator < (const number b) {
		return this -> v < b.v;
	}
}a[maxn];

struct pair {
	int l, r;
	const bool operator < (const pair b) {
		if (this -> r != b.r)
			return this -> r < b.r;
		return this->l < b.l;
	}
}p[maxn * 2];

int pcnt;

inline void insert_pair(int l, int r) {
	l = a[l].pos;
	r = a[r].pos;
	if (l > r)
		l ^= r ^= l ^= r;
	p[++pcnt].l = l;
	p[pcnt].r = r;
}

struct question {
	int l, r, pos;
	const bool operator < (const question b) {
		if (this -> r != b.r)
			return this -> r < b.r;
		return this->l < b.l;
	}
}q[maxm];

int c[maxn];

void add(int x) {
	for (; x <= n; x += lowbit(x))
		++c[x];
}

int query(int x) {
	int ans = 0;
	for (; x; x -= lowbit(x))
		ans += c[x];
	return ans;
}

signed main() {
	n = read();
	m = read();
	if (n == 1) {
		puts("0");
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		a[i].v = read();
		a[i].pos = i;
	}
	std :: sort(a + 1, a + 1 + n);

	insert_pair(1, 2);
	insert_pair(n - 1, n);
	
	for (int i = 2; i < n; ++i) {
		int dl = a[i].v - a[i - 1].v, dr = a[i + 1].v - a[i].v;
		if (dl <= dr)
			insert_pair(i, i - 1);
		if (dl >= dr)
			insert_pair(i, i + 1);
	}
	std :: sort(p + 1, p + 1 + pcnt);

	for (int i = 1; i <= m; ++i) {
		q[i].l = read();
		q[i].r = read();
		q[i].pos = i;
	}
	std :: sort(q + 1, q + 1 + m);

	int ans = 0;

	for (int i = 1, j = 1; i <= m; ++i) {
		for (; j <= pcnt && p[j].r <= q[i].r; ++j)
			add(p[j].l);
		ans += q[i].pos * (j - query(q[i].l - 1) - 1);
	}

	printf("%lld\n", ans);
	return 0;
}