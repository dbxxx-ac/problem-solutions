#include <bits/stdc++.h>

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

const int maxn = 35;
const int maxl = 25;
const int maxk = int(3e5) + 5;
char name[maxn][maxl];
char card[maxn][5][maxl];
char q[maxk][maxl];
int r = 0;
int nxt[maxn], pre[maxn];

inline int chg(int p, int x, int k) {
    char t = card[x][k][0];
    if (t == 'P')
        return 401;
    if (t == 'T')
        return 402;
    if (card[x][k][1] == 'O')
        return 403;
    if (t == 'C')
        return p << 1;
    if (t == 'D')
        return p >> 1;

    int ret = 0;
    for (int i = 1; i < strlen(card[x][k]); ++i)
        ret = (ret << 1) + (ret << 3) + (card[x][k][i] ^ 48);

    if (t == 'A')
        return p + ret;
    if (t == 'B')
        return p - ret;
    if (t == 'E')
        return ret;
    return -114514;
}

inline int checkma(int x) {
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            if (chg(0, x, j) == 400 + i)
                return j;
        }
    }
    return 0;
}

//DBACE
//CABDE

const int cmpa[] = {3, 2, 4, 1, 5}; // minp equal 
const int cmpb[] = {2, 3, 1, 4, 5}; // maxp equal 

inline void opt(int x, int k, int p) {
    if (p != 400)
        printf("%s used %s,now p=%d.\n", name[x], card[x][k], p);
    std :: swap(q[r], card[x][k]);
    --r;
}

int main() {
    int n = read(), m = read(), k = read();
    for (int i = 1; i <= n; ++i) {
        scanf("%s%s%s%s", name[i], card[i][1], card[i][2], card[i][3]);
        nxt[i] = i + 1;
        pre[i] = i - 1;
    }
    nxt[n] = 1;
    pre[1] = n;

    for (int i = k; i >= 1; --i)
        scanf("%s", q[i]);
    r = k;

    for (int _ = 1, i = 1, p = 0, dbl = 0, rev = 0; _ <= m; ++_, p = 0, dbl = 0, rev = 0) {
        printf("Round %d:\n", _);
        for (; ; i = rev ? pre[i]: nxt[i]) {
            if (dbl == 1) {
                int ma = checkma(i);
                if (ma) {
                    if (chg(0, i, ma) == 402)
                        rev ^= 1;
                    opt(i, ma, p);
                    continue;
                }
                int rep = 0;
                for (int j = 1; j <= 3; ++j) {
                    if (chg(p, i, j) > 99) // bao han mo fa pai
                        continue;
                    else if (rep == 0)
                        rep = j;
                    if (chg(p, i, j) < chg(p, i, rep))
                        rep = j;
                    if (chg(p, i, j) == chg(p, i, rep))
                        if (cmpa[card[i][j][0] - 'A'] < cmpa[card[i][rep][0] - 'A'])
                            rep = j;
                }
                if (rep == 0) {
                    break;
                }
                p = chg(p, i, rep);
                opt(i, rep, p);
                dbl = 0;
            }
            int ma = checkma(i), rep = 0;

            for (int j = 1; j <= 3; ++j) {
                //printf("%s %d\n", card[i][j], chg(p, i, j));
                if (chg(p, i, j) > 99) // bao han mo fa pai
                    continue;
                if (rep == 0)
                    rep = j;
                else if (chg(p, i, j) > chg(p, i, rep))
                    rep = j;
                else if (chg(p, i, j) == chg(p, i, rep))
                    if (cmpb[card[i][j][0] - 'A'] < cmpb[card[i][rep][0] - 'A'])
                        rep = j;
            }

            if (rep != 0) {
                p = chg(p, i, rep);
                opt(i, rep, p);
                continue;
            }

            if (ma) {
                if (chg(0, i, ma) == 403)
                    dbl = 1;
                if (chg(0, i, ma) == 402)
                    rev ^= 1;
                opt(i, ma, p);
            } else
                break;
        }

        //failed
        printf("%s lost the game.\n", name[i]);
        opt(i, 1, 400);
        opt(i, 2, 400);
        opt(i, 3, 400);
    }
}
 
/*
2 1 10
Rubyonly B9 A99 PASS
SuZipei C2 D2 A49
E49 DOUBLE PASS A19 A49 A99 A99 A99 A99 A99
 
 
3 2 25
Su A9 A19 B1
Ka TURN A9 C2
Ru DOUBLE D2 D2
A9 B9 C2 PASS PASS A9 A1 A99 A99 A99 A99 A99 A99 A99 A99 A99 A99 A99 A99 A99 A99 A99 A99 A99 A99  
*/