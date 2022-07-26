/*
 * @Author: crab-in-the-northeast 
 * @Date: 2022-07-06 02:55:11 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2022-07-10 18:53:47
 */

#include <bits/stdc++.h>

const int maxn = 2e7 + 5;
const int maxm = 2e7 + 5;

int z[maxm];

#define int long long

int p[maxn];
char A[maxn], B[maxm];

void get_z(char *P) {
    int m = strlen(P) - 1;
    for (int i = 2, k = 1; i <= m; ++i) {
        if (k + z[k] - i <= z[i - k + 1]) { // 第二种情况
        // 相当于 z[i - k + 1] >= k + z[k] - i
        // 也就是补齐后的紫色大于等于橙色时，进入第二种情况
            z[i] = k + z[k] - i; // 将z[i] 调到 k + z[k] - i，这是它的最小值
            if (z[i] < 0) // 判断，防止负数出现
                z[i] = 0;
            while (i + z[i] <= m && P[z[i] + 1] == P[i + z[i]])
                ++z[i]; // 暴力枚举，判断字符相等
            k = i; // 直接令 k = i
        } else
            z[i] = z[i - k + 1]; // 第一种情况
    }
    z[1] = m; // 题目中要求 z[1] = m，在算法处理后赋值
    return ;
}

void exkmp(char *T, char *P) {
    int n = strlen(T) - 1, m = strlen(P) - 1;
    for (int i = 1, k = 0; i <= n; ++i) {
        if (k + p[k] - i <= z[i - k + 1]) {
            p[i] = k + p[k] - i; 
            if (p[i] < 0)
                p[i] = 0;
            while (i + p[i] <= n && p[i] < m && P[p[i] + 1] == T[i + p[i]])
                ++p[i];
            k = i;
        } else
            p[i] = z[i - k + 1];
    }
    return ;
}

signed main() {
    scanf("%s%s", A + 1, B + 1);
    A[0] = B[0] = ' ';
    get_z(B);
    exkmp(A, B);
    int n = strlen(A) - 1, m = strlen(B) - 1;
    int ansz = 0, ansp = 0;
    for (int i = 1; i <= m; ++i)
        ansz ^= (z[i] + 1) * i;
    for (int i = 1; i <= n; ++i)
        ansp ^= (p[i] + 1) * i;
    printf("%lld\n%lld\n", ansz, ansp);
    return 0;
}
