/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-06 01:09:07 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-07 23:39:25
 */
#include <bits/stdc++.h>

const int maxn = 1e6 + 5;
const int maxm = 1e6 + 5;

char T[maxn];
char P[maxm];

//n 为文本串长度，m 为模式串长度

int fail[maxm];

std :: vector <int> v;

int KMP(char *T, char *P) {
    int n = strlen(T) - 1, m = strlen(P) - 1;
    for (int i = 1, j = 0; i <= n; ++i) {
        while (j > 0 && P[j + 1] != T[i])
            j = fail[j];
        if (P[j + 1] == T[i]) {
            ++j;
            if (j == m)
                v.push_back(i - m + 1);
        }
    }
    return 0;
}

void get_fail(char *P) {
    int m = strlen(P) - 1;
    for (int i = 2, j = 0; i <= m; ++i) {
        while (j > 0 && P[j + 1] != P[i])
            j = fail[j];
        if (P[j + 1] == P[i])
            ++j;
        fail[i] = j;
    }
}

int main() {
    std :: scanf("%s%s", T + 1, P + 1);
    T[0] = P[0] = ' ';
    get_fail(P);
    KMP(T, P);
    for (int i = 0; i < v.size(); ++i)
        printf("%d\n", v[i]);
    for (int i = 1; i < strlen(P); ++i)
        printf("%d ", fail[i]);
    return 0;
}