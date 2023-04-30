/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-07 16:01:16 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-07 19:34:12
 */
#include <bits/stdc++.h>
#define int long long
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

const int maxn = (int)2e5 + 5;
const int maxm = (int)2e5 + 5;
typedef std :: pair <int, int> pii;

std :: vector <pii> G[maxn];
// G[u] 存储一个顶点是 u 的边信息
// pii 第一项为边连接的另一个顶点 v，第二项为边编号
int wei[maxm]; // 记录边编号为 i 的边权

std :: unordered_map <int, int> eid;
// 这个用来根据边两边的点信息还原出边的编号
// 因为 umap 自带哈希函数不支持 pair
// 考虑给键值传个 u * n + v

namespace T {
    int fa[maxn], pred[maxn], dis[maxn];
    // 分别代表：
    // T 上 u 的父亲；
    // T 上连接 u 和 fa[u] 的边（称之为前驱边）编号；
    // D(1, u) = w(T(1, u)) 的值，也是原图上 1 到 u 的最短路
}
namespace R {
    int fa[maxn], pred[maxn], dis[maxn];
    // 分别代表：
    // R 上 u 的父亲；
    // R 上连接 u 和 fa[u] 的边（称之为前驱边）编号；
    // D(u, n) = w(R(u, n)) 的值，也是原图上 u 到 n 的最短路
}

int prd[maxn], sud[maxn];
int tag[maxm];
// tag[i] 记录 i 编号这条边在 E 上的下标，如果不在 E_P 上则为 0
int ans[maxn];
// ans[i] 记录删除 E_i 的最短路

std :: vector <int> ls[maxn];
std :: vector <int> rs[maxn];
// ls[i] 存放左端点在 i 的区间修改信息，rs[i] 存放右端点在 i 的区间修改信息

int s, t, n, k; // k 表示最短路 P 的边数

inline int getprd(int u) {
	return prd[u] = (prd[u] != -1 ? prd[u] : getprd(T :: fa[u]));
}
inline int getsud(int u) {
    return sud[u] = (sud[u] != -1 ? sud[u] : getsud(R :: fa[u]));
}

inline bool init() {
	std :: memset(T :: dis, 0x3f, sizeof(T :: dis));
	const int inf = T :: dis[0];
	T :: dis[s] = 0;
	std :: priority_queue <pii> q;
	q.push({0, s});
	while (!q.empty()) {
		int d = q.top().first, u = q.top().second;
		q.pop();
		if (d + T :: dis[u])
			continue;
		for (pii e : G[u]) {
			int v = e.first, id = e.second, w = wei[id];
			if (T :: dis[u] + w < T :: dis[v]) {
				T :: dis[v] = T :: dis[u] + w;
				T :: fa[v] = u;
				T :: pred[v] = id;
				q.push({-T :: dis[v], v});
			}
		}
	}

	if (T :: dis[t] >= inf)
		return false;
	
	std :: vector <int> P; // 这个 P 实际是 V_P
	for (int u = t; u; u = T :: fa[u])
		P.push_back(u);
	std :: reverse(P.begin(), P.end());
	k = (int)P.size() - 1;
	// 在 P 上，点编号 0~k，共 k+1 个；边编号 1~k，共 k 个。
	std :: memset(prd, -1, sizeof(prd));
    std :: memset(sud, -1, sizeof(sud));
    std :: memset(R :: dis, 0x3f, sizeof(R :: dis));
	for (int i = 0; i <= k; ++i) {
		prd[P[i]] = i; // 设置 P 上点的 prd
        sud[P[i]] = i;
		if (i >= 1)
        // 对于 i >= 1, P[i] 在 T 上的前驱边就是 E[i]
            tag[T :: pred[P[i]]] = i; // tag[i] 记录 i 编号这条边在 E 上的下标，如果不在 E_P 上则为 0
        R :: dis[P[i]] = T :: dis[t] - T :: dis[P[i]];
        // P[i] 到 t 的距离等于 s 到 t 的距离 - s 到 P[i] 的距离
        q.push({-R :: dis[P[i]], P[i]}); // 这些点的最短路确定，已经可以推入 dij 的优先队列了
        // 有个负号是因为本人 dij 的写法
        if (i < k) { 
            R :: fa[P[i]] = P[i + 1];
            R :: pred[P[i]] = T :: pred[P[i + 1]];
        }
	}

	while (!q.empty()) {
		int d = q.top().first, u = q.top().second;
		q.pop();
		if (d + R :: dis[u])
			continue;
		for (pii e : G[u]) {
			int v = e.first, id = e.second, w = wei[id];
			if (R :: dis[u] + w < R :: dis[v]) {
				R :: dis[v] = R :: dis[u] + w;
				R :: fa[v] = u;
				R :: pred[v] = id;
				q.push({-R :: dis[v], v});
			}
		}
	}

    for (int u = 1; u <= n; ++u) {
        if (T :: dis[u] < inf) {
            getprd(u);
            getsud(u); // 处理好所有点的 prd 和 sud
        }
    }

	return true;
}

signed main() {
	n = read();
	int m = read();
	for (int i = 1; i <= m; ++i) {
		int u = read(), v = read(), w = read();
		G[u].push_back({v, i});
		G[v].push_back({u, i});
		wei[i] = w;
		if (u > v)
			std :: swap(u, v);
		eid[u * n + v] = i;
	}

	s = read(), t = read();
	if (!init()) {
		int q = read();
		while (q--)
			puts("Infinity");
	}
	
	for (int u = 1; u <= n; ++u) {
		for (pii e : G[u]) {
            // 这种枚举方式下，一条边 (u, v) 会被作为 (u, v) 和 (v, u) 两次被枚举到，正是我们所期望的
			int v = e.first, id = e.second, w = wei[id];
			if (tag[id])
				continue;
			if (prd[u] < sud[v]) {
				int W = T :: dis[u] + w + R :: dis[v];
				ls[prd[u] + 1].push_back(W);
				rs[sud[v]].push_back(W);
			}
		}
	}

	std :: multiset <int> S;
	std :: memset(ans, 0x3f, sizeof(ans));
	const int inf = ans[0];
	for (int i = 1; i <= k; ++i) {
		for (int d : ls[i])
			S.insert(d);
		if (!S.empty())
			ans[i] = *S.begin();
		for (int d : rs[i])
			S.erase(S.find(d));
	}

	int q = read();
	while (q--) {
		int u = read(), v = read();
		if (u > v)
			std :: swap(u, v);
		int id = eid[u * n + v];
		if (tag[id]) {
			int W = ans[tag[id]];
			if (W == inf)
				puts("Infinity");
			else
				printf("%lld\n", W);
		} else
			printf("%lld\n", T :: dis[t]);
	}

	return 0;
}