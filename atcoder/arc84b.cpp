#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
using namespace std;

const int NR = 1e6 + 5;
int k;
int ans;
bool vis[NR];
struct node {
	int num, w;
};
deque<node> d;

void bfs() {
	d.push_front(node{1, 1});
	vis[1] = true;
	while (!d.empty()) {
		int num = d.front().num, w = d.front().w;
		d.pop_front();
		if (num == 0) {
			cout << w << endl;
			return;
		}
		if (!vis[10 * num % k]) {
			d.push_front(node{10 * num % k, w});
			vis[10 * num % k] = true;
		}
		if (!vis[num + 1]) {
			d.push_back(node{num + 1, w + 1});
		}
	}
	return;
}

int main() {
	cin >> k;
	bfs();
	return 0;
}