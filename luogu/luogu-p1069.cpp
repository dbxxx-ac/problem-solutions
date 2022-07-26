/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-10-02 20:06:20 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-10-02 21:52:59
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>

const int maxm1 = 30005;

int prime_num[maxm1], cnt;
bool isprime[maxm1];

void prime(int n) {
    std :: memset(isprime, true, sizeof(isprime));
    isprime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (isprime[i]) prime_num[++cnt] = i;
        for (int j = 1; j <= cnt && i * prime_num[j] <= n; ++j) {
            isprime[i * prime_num[j]] = false;
            if (i % prime_num[j] == 0) break;
        }
    }
}

int tube_prime[maxm1], cell_prime[maxm1];

int main() {
    int n, m1, m2, ans = INT_MAX;
    std :: scanf("%d", &n);
    std :: scanf("%d %d", &m1, &m2);

    prime(30000);
    for (int i = 1, div = m1; div != 1; ++i) {
        while (div % prime_num[i] == 0) {
            tube_prime[i] += m2;
            div /= prime_num[i];
        }
    }

    for (int i = 1; i <= n; ++i) {
        int s, need = 0;
        std :: scanf("%d", &s);
        std :: memset(cell_prime, 0, sizeof(cell_prime));
        for (int j = 1, div = s; j <= cnt; ++j) {
            while (div % prime_num[j] == 0) {
                ++cell_prime[j];
                div /= prime_num[j];
            }
        }

        bool valid = true;
        for (int j = 1; j <= cnt; ++j) {
            if (tube_prime[j] != 0 && cell_prime[j] == 0) {
                valid = false;
                break;
            }
            if (tube_prime[j] != 0) {
                int t = tube_prime[j] / cell_prime[j] + (tube_prime[j] % cell_prime[j] ? 1 : 0);
                if (t > need) need = t;
            }
        }

        if (valid && need < ans) ans = need;
    }

    if (ans == INT_MAX) puts("-1");
    else std :: printf("%d\n", ans);
    return 0;
}