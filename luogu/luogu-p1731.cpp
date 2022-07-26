/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-02-05 13:35:49 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-02-05 15:37:44
 */
#include <iostream>
#include <cstdio>

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

inline int S(int r, int h) {
	return 2 * r * h;
}

inline int V(int r, int h) {
	return r * r * h;
}

const int inf = 2147483600;
int n, m, ans = inf;

const int maxm = 20;
int mins[maxm], minv[maxm];

inline int min(int a, int b) {
	return a < b ? a : b;
}

void dfs(int now, int curs, int curv, int lstr, int lsth) {
	if (now == m + 1) {
		if (curv == n)
			ans = min(curs, ans);
		return ;
	}
	if (curs + mins[now + 1] >= ans)
		return ;
	if (curv + minv[now + 1] >= n)
		return ;
	if (curs + 2 * (n - curv) / (lstr - 1) >= ans)
		return ;
	
	for (int i = lstr - 1; i > m - now; --i) {
		if (now == 1)
			curs = i * i;
		const int maxh = min(lsth - 1, (n - curv - minv[now + 1]) / i / i);
		for (int j = maxh; j > m - now; --j)
			dfs(now + 1, curs + S(i, j), curv + V(i, j), i, j);
	}

	return ;
}

int main() {
	n = read();
	m = read();
	for (int i = m; i >= 1; --i) {
		mins[i] = mins[i + 1] + S(m - i + 1, m - i + 1);
		minv[i] = minv[i + 1] + V(m - i + 1, m - i + 1);
	}
	dfs(1, 0, 0, n + 1, n + 1);
	if (ans == inf)
		puts("0");
	else
		printf("%d\n", ans);
	return 0;
}