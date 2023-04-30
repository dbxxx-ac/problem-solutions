/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-12-04 01:03:11 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-12-04 13:35:14
 */
#include <bits/stdc++.h>
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

const int maxn = 305;
const int maxm = (int)2e6 + 5;

int a[maxm];
std :: deque <int> st[maxn];
int id[maxn * 2]; // 维护所在栈编号，局面未出现则为 0

typedef std :: pair <int, int> pii;
std :: vector <pii> ans;

inline void pu(int s) {
    ans.emplace_back(s, 0);
}

inline void de(int s, int t) {
    ans.emplace_back(s, t);
}

int spt; // 辅助栈编号
std :: queue <int> q; // 维护空栈

inline bool simple(int x) { // 尝试简单相消
    int s = id[x];
    if (!s) { // 如果 x 目前不在局面
        do {
            if (q.empty())
                return false;
            s = q.front();
        } while (s == spt);
        id[x] = s = q.front();
        q.pop();
        pu(s);
        st[s].push_back(x);
    } else { // 如果 x 目前在局面中
        id[x] = 0;
        q.push(s);
        if (x == st[s].back()) {
            pu(s);
            st[s].pop_back();
        } else {
            pu(spt);
            de(spt, s);
            st[s].pop_front();
        }
    }
    return true;
}

int main() {
    for (int T = read(); T; --T) {
        int n = read(), m = read(); read();
        for (int i = 1; i <= m; ++i)
            a[i] = read();
        std :: memset(id, 0, sizeof(id));
        ans.clear();
        spt = n;

        while (!q.empty())
            q.pop();
        for (int i = 1; i < n; ++i) {
            q.push(i);
            q.push(i);
        }
        
        for (int i = 1; i <= m; ++i) if (!simple(a[i])) {
            int p = a[i];
            int r = i + 1, x = a[r];
            for (; r <= m && x != p && st[id[x]].back() == x; ++r, x = a[r]);
            // 此时 r 是 i 后第一个不在栈顶上的下标，x 是 a[r]

            if (x == p) {
                pu(spt);
                for (int j = i + 1; j < r; ++j)
                    simple(a[j]);
                pu(spt);
            } else {
                int s = id[x], y = st[s].back();
                bool evn = true; // 中间栈顶中，y 的数量是否为偶数
                for (int j = i + 1; j < r; ++j)
                    if (a[j] == y)
                        evn = !evn;
                if (evn) {
                    pu(s);
                    st[s].push_back(p);
                    for (int j = i + 1; j < r; ++j) {
                        if (a[j] == y)
                            pu(spt);
                        else
                            simple(a[j]);
                    }
                    pu(spt);
                    de(spt, s);
                    st[s].pop_front();
                    // st[s] 从栈底到栈顶，原先为 x, y，现在为 y, p
                    // 依此更新 id
                    id[x] = 0;
                    id[p] = s;
                } else {
                    pu(spt);
                    st[spt].push_back(p);
                    for (int j = i + 1; j < r; ++j) {
                        if (a[j] == y)
                            pu(s); // 注意这里不要直接 simple(a[j])
                        // 原因是 s 即将变成 spt，所以暂时不能让 s 弹入 q
                        // 特判让 simple 函数此时不把 s 不弹入 q 也不行
                        // 假如 3 1 2 1 1 1 ....
                        // 如果直接不弹入 q，会造成后面的一串 1 1 1 无法正确弹入 s
                        // 最后暴力扫队列把 s 删除复杂度也不对
                        // 所以正确的做法就是不用 simple 函数
                        else
                            simple(a[j]);
                    }
                    pu(s);
                    st[s].clear();
                    // 原先辅助栈 spt 此时存在一个元素 p
                    // s 原先栈底到栈顶为 x，y， 现在为空
                    // s 作为新的 spt
                    // 依此更新 id 和 q
                    id[x] = id[y] = 0;
                    id[p] = spt;
                    q.push(spt);
                    spt = s;
                }
            }

            i = r; // 注意循环会自带 ++i，下一次循环 i = r + 1
        }

        printf("%d\n", (int)ans.size());
        for (pii p : ans) {
            if (p.second)
                printf("2 %d %d\n", p.first, p.second);
            else
                printf("1 %d\n", p.first);
        }
    }
}