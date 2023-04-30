/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-11-16 01:29:09 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-11-16 03:11:11
 */
#include <bits/stdc++.h>
inline std :: string rest() {
    std :: string s;
    char ch = getchar();
    for (; !isgraph(ch); ch = getchar());
    for (; isgraph(ch); ch = getchar())
        s.push_back(ch);
    return s;
}

const int maxn = (int)1e6 + 5;
bool ok[maxn];
    
std :: stack <std :: pair <char, int> > st;

int main() {
    std :: string s = rest();
    int n = s.length();
    s = " " + s;

    for (int i = 1; i <= n; ++i) {
        char c = s[i];
        if (((c == ')' && !st.empty()) && st.top().first == '(')
        || ((c == ']' && !st.empty()) && st.top().first == '[')) {
            ok[i] = ok[st.top().second] = true;
            st.pop();
        } else
            st.push({c, i});
    }

    int ansl = 0, ansr = 0;

    for (int l = 1, r = 1; r <= n; ++r) {
        if (ok[r] && !ok[r + 1]) {
            if (r - l + 1 > ansr - ansl + 1) {
                ansl = l;
                ansr = r;
            }
        } else if (!ok[r] && ok[r + 1])
            l = r + 1;
    }

    for (int i = ansl; i <= ansr; ++i)
        putchar(s[i]);
    
    puts("");
    return 0;
}