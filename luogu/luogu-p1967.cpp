/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-03-26 15:06:17 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-03-26 15:30:50
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#include <vector>

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

const int maxn = 10005;
const int maxm = 50005;
const int maxq = 30005;

std :: set <int> s[maxn];
int ans[maxq];

struct road {
	int u, v, z;
	inline void set(int u, int v, int z) {
		this -> u = u;
		this -> v = v;
		this -> z = z;
	}
	const bool operator < (const road b) {
		return this -> z > b.z;
	}
}r[maxm];

int fa[maxn];
int find(int x) {
	while (x != fa[x])
		x = fa[x] = fa[fa[x]];
	return x;
}

int main() {
	int n = read(), m = read();
	for (int i = 1; i <= m; ++i) {
		int u = read(), v = read(), z = read();
		r[i].set(u, v, z);
	}
	int q = read();
	for (int i = 1; i <= q; ++i) {
		int u = read(), v = read();
		s[u].insert(i);
		s[v].insert(i);
	}

	for (int i = 1; i <= n; ++i)
		fa[i] = i;
	std :: memset(ans, -1, (q + 3) * sizeof(int));
	std :: sort(r + 1, r + 1 + m);

	for (int i = 1; i <= m; ++i) {
		int u = r[i].u, v = r[i].v, z = r[i].z;
		int ufa = find(u), vfa = find(v);
		if (ufa == vfa)
			continue;
		if (s[ufa].size() > s[vfa].size())
			ufa ^= vfa ^= ufa ^= vfa;
		std :: vector <int> vec;
		while (!vec.empty())
			vec.pop_back();
		for (std :: set <int> :: iterator it = s[ufa].begin(); it != s[ufa].end(); ++it) {
			int i = *it;
			if (s[vfa].count(i)) {
				ans[i] = z;
				vec.push_back(i);
			}
			else
				s[vfa].insert(i);
		}
		for (int i = 0; i < vec.size(); ++i)
			s[vfa].erase(vec[i]);
		fa[ufa] = vfa;
	}

	for (int i = 1; i <= q; ++i)
		printf("%d\n", ans[i]);
	return 0;
}