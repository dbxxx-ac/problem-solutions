// Skyqwq
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> void inline read(T &x) {
	x = 0; char s = getchar(); int f = 1;
	while (s < '0' || s > '9') { if (s == '-') { f = -1; } s = getchar(); }
	while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
	x *= f;
}

template <typename T> bool inline chkMax(T &x, T y) { return y > x ? x = y, 1 : 0; }
template <typename T> bool inline chkMin(T &x, T y) { return y < x ? x = y, 1 : 0; }

const int P = 1e9 + 7, N = 5e5 + 5;

int n, a[N], f[N], sz[N], c[N], d[N], t, inv[N];

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}

void inline merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	if (sz[x] > sz[y]) swap(x, y);
	f[x] = y, sz[y] += sz[x];
}


vector<int> g[N];
vector<PII> e[N];


bool st[N];

int pr[N], tot, p0[N];

vector<PII> fc[N];

void inline clr() {
	t = 0;
	for (int i = 1; i <= n; i++) c[i] = d[i] = 0, g[i].clear();
}

int now, cnt[N];

int inline get(int x) {
	int mx = 1;
	for (int v: g[x]) cnt[v]++;
	for (PII v: e[x]) cnt[v.fi] += v.se;
	for (int v: g[x])
		if (cnt[v]) chkMax(mx, v), cnt[v] = 0;
	for (PII v: e[x])
		if (cnt[v.fi]) chkMax(mx, v.fi), cnt[v.fi] = 0;
	return mx;
}

void inline chg(int x, int d) {
	for (PII o: fc[x]) {
		now = 1ll * now * inv[get(o.fi)] % P;
		e[o.fi].pb(mp(o.se, d));
		now = 1ll * now * get(o.fi) % P;
	}
}

void inline del(int x) {
	for (PII o: fc[x])
		e[o.fi].clear();
}

void inline add(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}

void inline work() {
	now = 1;
	for (int i = 1; i <= n; i++) {
		if (g[i].size()) {
			sort(g[i].begin(), g[i].end(), greater<int>() );
			while (g[i].size() > 3) g[i].pop_back();
			now = 1ll * now * g[i][0] % P;
		}
	}
	int ans = 0;
	for (int i = 1; i <= t; i++) {
		int u = d[i];
		if (c[u] > 1) {
			int la = now;
			chg(u + u, 1);
			chg(u, -1);
			chg(u, -1);
			del(u + u); del(u);
			add(ans, 1ll * now * c[u] % P * (c[u] - 1) % P * u % P * u % P);
			now = la;
		}
		for (int j = i + 1; j <= t; j++) {
			int v = d[j];
			int la = now;
			chg(u + v, 1), chg(u, -1), chg(v, -1);
			add(ans, 2ll * now * c[u] % P * c[v] % P * u % P * v % P);
			del(u + v), del(u), del(v);
			now = la;
		}
	}
	printf("%d\n", ans);
}


void inline apd(int x) {
	for (PII o: fc[x])
		g[o.fi].pb(o.se);
}


void inline prw(int n) {
	p0[1] = 1;
	inv[1] = 1;
	for (int i = 2; i <= n; i++) {
		inv[i] = ((LL)P - P / i) * inv[P % i] % P;
	}
	for (int i = 2; i <= n; i++) {
		if (!st[i]) pr[++tot] = i, p0[i] = i;
		for (int j = 1; pr[j] * i <= n; j++) {
			st[i * pr[j]] = 1;
			p0[i * pr[j]] = pr[j];
			if (i % pr[j] == 0) break;
		}
	}
	for (int i = 1; i <= n; i++) {
		int x = i;
		while (x != 1) {
			int p = p0[x], v = 1;
			while (x % p == 0) v *= p, x /= p;
			fc[i].pb(mp(p, v));
		}
	}
}

int main() {
	//freopen("perm.in", "r", stdin);
	//freopen("perm.out", "w", stdout);
	prw(5e5);
	int T; read(T);
	while (T--) {
		read(n);
		for (int i = 1; i <= n; i++) read(a[i]), f[i] = i, sz[i] = 1;
		for (int i = 1; i <= n; i++) merge(i, a[i]);
		for (int i = 1; i <= n; i++) {
			if (find(i) == i) {
				c[sz[i]]++;
				apd(sz[i]);
                printf("%d ", sz[i]);
			}
		}
		for (int i = 1; i <= n; i++)
			if (c[i]) d[++t] = i;
		work();
		clr();
	}
}