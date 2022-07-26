/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-10 08:02:14 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-11 17:54:36
 */
#include <bits/stdc++.h>
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

typedef unsigned long long ull;
const int maxk = 35;
const int maxn = 1e5 + 5;
int a[maxk];

const ull base = 100005;
const ull mods[] = {(ull)1e9 + 7, 19260817, 19660813};
ull hash(int n, int p) {
	ull x = 0;
	for (int i = 0; i < n; ++i)
		x = (x * base + (ull)(a[i] + maxn)) % mods[p];
	return x;
}

struct node {
	ull ha[3];
	int id;
}h[maxn];

bool cmp(node a, node b) {
	if (a.ha[0] == b.ha[0])
		return a.id < b.id;
	return a.ha[0] < b.ha[0];
}

inline int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n = read(), k = read();
	for (int j = 0; j < 3; ++j)
		h[0].ha[j] = hash(k, j);
	for (int i = 1; i <= n; ++i) {
		int x = read();
		for (int j = 0; j < k; ++j)
			a[j] += ((x >> j) & 1) - (x & 1);
		for (int j = 0; j < 3; ++j)
			h[i].ha[j] = hash(k, j);
		h[i].id = i;
	}

	std :: sort(h, h + 1 + n, cmp);
	int ans = 0, lst = 0;
	for (int i = 0; i < n; ++i) {
		bool f = true;
		for (int j = 0; j < 3; ++j)
			if (h[i].ha[j] != h[i + 1].ha[j])
				f = false;
		if (!f) {
			ans = max(ans, h[i].id - h[lst].id);
			lst = i + 1;
		}
	}
	ans = max(ans, h[n].id - h[lst].id);

	printf("%d\n", ans);
	return 0;
}
