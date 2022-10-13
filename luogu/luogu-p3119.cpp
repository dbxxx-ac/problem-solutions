// 10秒想出来缩点和分层图。然后忘了缩点板子回忆了将近一个
// 小时的板子。无语

// 好的又卡 spfa 上了。几个月没写 spfa 了（一直写 dijkstra）
// 无语。。。。。。。。

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

const int maxn = (int)1e5 + 5;

std :: vector <int> g[maxn];
std :: vector <int> G[maxn << 1];

int times = 0;
int bcc[maxn], low[maxn], dfn[maxn], siz[maxn << 1];
int bnt = 0;
bool ins[maxn];

inline bool getmin(int &a, int b) {
	return b < a ? a = b, true : false;
}

std :: stack <int> s;
inline void tarjan(int u) {
	dfn[u] = low[u] = ++times;
	ins[u] = true;
	s.push(u);
	
	for (auto v : g[u]) {
		if (dfn[v] == 0) {
			tarjan(v);
			// printf("%d %d\n", low[u], low[v]);
			getmin(low[u], low[v]); 
			// printf("%d %d\n", low[u], low[v]);
		} else if (ins[v])
			getmin(low[u], dfn[v]);
	}

	if (dfn[u] == low[u]) {
		++bnt;
		while (s.top() != u) {
			int x = s.top();
			s.pop();
			++siz[bnt];
			bcc[x] = bnt;
			ins[x] = false;
		}
		s.pop();
		++siz[bnt];
		bcc[u] = bnt;
		ins[u] = false;
	}
}

bool vis[maxn << 1];
int dis[maxn << 1];

inline int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n = read(), m = read();
	while (m--) {
		int u = read(), v = read();
		g[u].push_back(v);
	}

	for (int u = 1; u <= n; ++u)
		if (dfn[u] == 0)
			tarjan(u);
	
	if (bnt == 1) {
		printf("%d\n", n);
		return 0;
	}
	// // puts("hi");
	// printf("%d\n", n);
	// // puts("hi");
	// for (int u = 1; u <= n; ++u)
	// 	printf("%d ", bcc[u]);
	// puts("");
	
	std :: copy(siz + 1, siz + 1 + bnt, siz + 1 + bnt);
	// for (int i = 1; i <= bnt + bnt; ++i)
	// 	printf("%d ", siz[i]);
	// puts("");

	for (int i = 1; i <= n; ++i) {
		for (auto j : g[i]) {
			int u = bcc[i], v = bcc[j];
			if (u == v)
				continue;
			G[u].push_back(v);
			//G[u].push_back(v + bnt);
			G[v].push_back(u + bnt);
			G[u + bnt].push_back(v + bnt);
		}
	}

	std :: queue <int> q;
	q.push(bcc[1]);

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (auto v : G[u]) {
			if (dis[v] < dis[u] + siz[u]) {
				dis[v] = dis[u] + siz[u];
				if (!vis[v]) {
					q.push(v);
					vis[v] = true;
				}
			}
		}
		// printf("%d\n", u);
	}

	
	printf("%d\n", dis[bcc[1] + bnt]);
	return 0;
}