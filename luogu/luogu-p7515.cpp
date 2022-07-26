/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-02-02 23:52:50 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-02-03 01:10:11
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

const int maxn = 305, maxm = 305;
const int maxa = (int)1e6;

struct edge {
	int nxt, v, val;
}e[maxn * maxm * 3];

int head[maxn + maxm], tot[maxn + maxm], dis[maxn + maxm], cnt;
bool vis[maxn + maxm];

void insert(int u, int v, int val) {
	e[++cnt].v = v;
	e[cnt].val = val;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}

bool spfa(int s, int n, int m) {
	std :: queue <int> q;
	dis[s] = 0;
	vis[s] = true;
	q.push(s);

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].v;
			if (dis[v] > dis[u] + e[i].val) {
				dis[v] = dis[u] + e[i].val;
				++tot[u];
				if (tot[u] > n + m)
					return false;
				if (!vis[v]) {
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}

	return true;
}

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

inline bool isodd(int x) {
	return x & 1;
}

int a[maxn][maxm], b[maxn][maxm];

int main() {
	int T = read();
	while (T--) {
		std :: memset(a, 0, sizeof(a));
		std :: memset(head, 0, sizeof(head));
		std :: memset(tot, 0, sizeof(tot));
		std :: memset(dis, 0x3f, sizeof(dis));
		std :: memset(vis, false, sizeof(vis));
		cnt = 0;
		
		int n = read(), m = read();
		for (int i = 1; i < n; ++i)
			for (int j = 1; j < m; ++j)
				b[i][j] = read();

		for (int i = 2; i <= n; ++i)
			for (int j = 2; j <= m; ++j)
				a[i][j] = b[i - 1][j - 1] - a[i - 1][j] - a[i][j - 1] - a[i - 1][j - 1];
		
		for (int i = 1; i <= n + m; ++i)
			insert(0, i, 0);
			
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				if (isodd(i + j)) {
					insert(i, j + n, a[i][j]);
					insert(j + n, i, maxa - a[i][j]);
				} else {
					insert(i, j + n, maxa - a[i][j]);
					insert(j + n, i, a[i][j]);
				}
		
		if (!spfa(0, n, m)) {
			puts("NO");
			continue;
		}
		puts("YES");
		
		for (int i = 1; i <= n; ++i, puts(""))
			for (int j = 1; j <= m; ++j) {
				if (isodd(i + j))
					a[i][j] += dis[i] - dis[j + n];
				else
					a[i][j] -= dis[i] - dis[j + n];
				printf("%d ", a[i][j]);
			}
		// i + j odd
		// i j + n a[i][j]
		// j + n i 1e6-a[i][j]
		//else
		// i j + n 1e6 - a[i][j]
		// j + n i a[i][j]
	}
	
	return 0;
}