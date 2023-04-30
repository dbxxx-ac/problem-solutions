/*
 * @Author: crab-in-the-northeast 
 * @Date: 2023-04-07 19:01:35 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2023-04-07 22:22:22
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
int wei[maxm], us[maxm], vs[maxm];
std :: vector <int> ls[maxn], rs[maxn];

int n, k;
namespace T {
    int fa[maxn], pred[maxn], dis[maxn];
}
namespace R {
    int fa[maxn], pred[maxn], dis[maxn];
}

int prd[maxn], sud[maxn], ans[maxn];
int tag[maxm];

inline int getprd(int u) {
	return prd[u] = (prd[u] != -1 ? prd[u] : getprd(T :: fa[u]));
}
inline int getsud(int u) {
    return sud[u] = (sud[u] != -1 ? sud[u] : getsud(R :: fa[u]));
}

inline void init() {
	std :: memset(T :: dis, 0x3f, sizeof(T :: dis));
	const int inf = T :: dis[0];
	T :: dis[1] = 0;
	std :: priority_queue <pii> q;
	q.push({0, 1});
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
	
	std :: vector <int> P;
	for (int u = n; u; u = T :: fa[u])
		P.push_back(u);
	std :: reverse(P.begin(), P.end());
	k = (int)P.size() - 1;
	std :: memset(prd, -1, sizeof(prd));
    std :: memset(sud, -1, sizeof(sud));
    std :: memset(R :: dis, 0x3f, sizeof(R :: dis));
	for (int i = 0; i <= k; ++i) {
		prd[P[i]] = i;
        sud[P[i]] = i;
		if (i >= 1)
            tag[T :: pred[P[i]]] = i;
        R :: dis[P[i]] = T :: dis[n] - T :: dis[P[i]];
        q.push({-R :: dis[P[i]], P[i]});
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
            getsud(u);
        }
    }
}

signed main() {
	n = read();
	int m = read(), q = read();
	for (int i = 1; i <= m; ++i) {
		int u = us[i] = read(), v = vs[i] = read(), w = read();
		G[u].push_back({v, i});
		G[v].push_back({u, i});
		wei[i] = w;
	}

	init();

	for (int u = 1; u <= n; ++u) {
		for (pii e : G[u]) {
			int v = e.first, id = e.second, w = wei[id];
			if (!tag[id] && prd[u] < sud[v]) {
				int W = T :: dis[u] + w + R :: dis[v];
				ls[prd[u] + 1].push_back(W);
				rs[sud[v]].push_back(W);
			}
		}
	}

	std :: multiset <int> S;
	std :: memset(ans, 0x3f, sizeof(ans));
	for (int i = 1; i <= k; ++i) {
		for (int d : ls[i])
			S.insert(d);
		if (!S.empty())
			ans[i] = *S.begin();
		for (int d : rs[i])
			S.erase(S.find(d));
	}

	while (q--) {
		int t = read(), x = read(), u = us[t], v = vs[t], w = wei[t];
		printf("%lld\n", tag[t] ? 
			std :: min(ans[tag[t]], T :: dis[n] - w + x) : 
			std :: min({T :: dis[n], T :: dis[u] + x + R :: dis[v], T :: dis[v] + x + R :: dis[u]}));
	}

	return 0;
}