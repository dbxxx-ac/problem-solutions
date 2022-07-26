/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-09-08 20:12:24 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-09-09 22:46:56
 */
#include <iostream>
#include <cstdio>
#include <string>

const int maxm = 2005;
const int maxn = 15;

struct node {
    int cardnum, health, next, last;
    char identity, card[maxm];
    bool Z;
}a[maxn];

char cards[maxm];

char identity[maxn];

int n, m;

int fpnum;

bool ended;

void GetCard(int idx) {
    if (m == 0) m = 1;
    a[idx].card[++a[idx].cardnum] = cards[m];
    --m;
}

void all_kill(int killer, int deader) {
    for (int i = 1; i <= a[deader].cardnum; ++i) {
        if (a[deader].card[i] == 'P') {
            a[deader].card[i] = 'X';
            ++a[deader].health;
            return ;
        }
    }

    a[a[deader].last].next = a[deader].next;
    a[a[deader].next].last = a[deader].last;

    if (deader == 1) {
        ended = true;
        return ;
    }

    if (a[deader].identity == 'F') --fpnum;
    if (fpnum == 0) {
        ended = true;
        return ;
    }

    if (a[deader].identity == 'F') {
        for (int i = 1; i <= 3; ++i)
            GetCard(killer);
    }

    if (a[killer].identity == 'M' && a[deader].identity == 'Z') {
        a[killer].cardnum = 0;
        a[killer].Z = false;
    }
}

void kill(int killer, int hurter) {
    for (int i = 1; i <= a[hurter].cardnum; ++i) {
        if (a[hurter].card[i] == 'D') {
            a[hurter].card[i] = 'X';
            return ;
        }
    }

    --a[hurter].health;
    if (a[hurter].health == 0) all_kill(killer, hurter);
}

bool NoMoreHurts(int x1, int x2, bool f) {
    for (int i = x1; true; i = a[i].next) {
        if (f) {
            if (identity[x2] == a[i].identity || (identity[x2] == 'Z' && a[i].identity == 'M') || (identity[x2] == 'M' && a[i].identity == 'Z')) {
                for (int j = 1; j <= a[i].cardnum; ++j) {
                    if (a[i].card[j] == 'J') {
                        a[i].card[j] = 'X';
                        identity[i] = a[i].identity;
                        return !NoMoreHurts(i, x1, false);
                    }
                }
            }
        } else {
            if (((a[i].identity == 'Z' || a[i].identity == 'M') && identity[x1] == 'F') || (a[i].identity == 'F' && (identity[x1] == 'Z' || identity[x1] == 'M'))) {
                for (int j = 1; j <= a[i].cardnum; ++j) {
                    if (a[i].card[j] == 'J') {
                        a[i].card[j] = 'X';
                        identity[i] = a[i].identity;
                        return !NoMoreHurts(i, x1, false);
                    }
                }
            }
        }

        if (a[i].next == x1) break;
    }

    return false;
}

void NanZhuInvade(int x) {
    for (int i = a[x].next; i != x; i = a[i].next) {
        if (!NoMoreHurts(x, i, true)) {
            int j;
            for (j = 1; j <= a[i].cardnum; ++j) {
                if (a[i].card[j] == 'K') {
                    a[i].card[j] = 'X';
                    break;
                }
            }
            if (a[i].cardnum < j) {
                --a[i].health;
                if (i == 1 && identity[x] == 'X')
                    identity[x] = 'L';
                if (a[i].health == 0)
                    all_kill(x, i);
                if (ended) return ;
            }
        }
    }
}

void battle(int x1, int x2) {
    if (NoMoreHurts(x1, x2, true)) return ;
    if (x1 == 1 && a[x2].identity == 'Z') {
        --a[x2].health;
        if (a[x2].health == 0) all_kill(x1, x2);
        return ;
    }

    for (int j = 1, k = 1;;) {
        while (a[x2].card[j] != 'K' && j <= a[x2].cardnum) ++j;
        if (a[x2].cardnum < j) {
            --a[x2].health;
            if (a[x2].health == 0) all_kill(x1, x2);
            return ;
        } else
            a[x2].card[j] = 'X';
        
        while (a[x1].card[k] != 'K' && k <= a[x1].cardnum) ++k;
        if (a[x1].cardnum < k) {
            --a[x1].health;
            if (a[x1].health == 0) all_kill(x2, x1);
            return ;
        } else
            a[x1].card[k] = 'X';
    }
}

void ManyShoots(int x) {
    for (int i = a[x].next; i != x; i = a[i].next) {
        if (!NoMoreHurts(x, i, true)) {
            int j;
            for (j = 1; j <= a[i].cardnum; ++j) {
                if (a[i].card[j] == 'D') {
                    a[i].card[j] = 'X';
                    break;
                }
            }
            if (a[i].cardnum < j) {
                --a[i].health;
                if (i == 1 && identity[x] == 'X')
                    identity[x] = 'L';
                if (a[i].health == 0)
                    all_kill(x, i);
                if (ended) return ;
            }
        }
    }
}

void round() {
    if (fpnum == 0) return ;
    ended = false;

    for (int i = 1; i; i = a[i].next) {
        for (int j = 1; j <= 2; ++j)
            GetCard(i);
        bool can_kill = true;

        for (int j = 1; j <= a[i].cardnum; ++j) {
            if (a[i].card[j] != 'X') {
                if (a[i].health == 0) break;
                if (a[i].card[j] == 'P') {
                    if (a[i].health != 4) {
                        a[i].card[j] = 'X';
                        ++a[i].health;
                    }
                } else if (a[i].card[j] == 'K') {
                    if (can_kill || a[i].Z) {
                        if ((a[i].identity != 'M' || identity[a[i].next] == 'L' || identity[a[i].next] == 'F') && (a[i].identity != 'Z' || identity[a[i].next] == 'F') && (a[i].identity != 'F' || identity[a[i].next] == 'Z' || identity[a[i].next] == 'M')) {
                            a[i].card[j] = 'X';
                            kill(i, a[i].next);
                            identity[i] = a[i].identity;
                            can_kill = false;
                            if (ended) return ;
                        }
                    } 
                } else if (a[i].card[j] == 'F') {
                    if (a[i].identity == 'F') {
                        a[i].card[j] = 'X';
                        battle(i, 1);
                        identity[i] = a[i].identity;
                        if (ended) return ;
                        j = 0;
                    } else {
                        for (int k = a[i].next; k != i; k = a[k].next) {
                            if ((a[i].identity == 'M' && (identity[k] == 'L' || identity[k] == 'F')) || (a[i].identity == 'Z' && identity[k] == 'F')) {
                                a[i].card[j] = 'X';
                                battle(i, k);
                                identity[i] = a[i].identity;
                                if (ended) return ;
                                j = 0;
                                break;
                            }
                        }
                    }
                } else if(a[i].card[j] == 'N') {
                    a[i].card[j] = 'X';
                    NanZhuInvade(i);
                    if (ended) return ;
                    j = 0;
                } else if (a[i].card[j] == 'W') {
                    a[i].card[j] = 'X';
                    ManyShoots(i);
                    if (ended) return ;
                    j = 0;
                } else if (a[i].card[j] == 'Z') {
                    a[i].card[j] = 'X';
                    a[i].Z = true;
                    j = 0;
                }
            }
        }
    }
}

int main() {
    std :: scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        a[i].next = i + 1;
        a[i].last = i - 1;
    }
    a[1].last = n;
    a[n].next = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < maxm; ++j)
            a[i].card[j] = 'X';
        char current_str[maxn];
        std :: scanf("%s", current_str);
        a[i].identity = current_str[0];
        for (int j = 1; j <= 4; ++j) {
            std :: scanf("%s", current_str);
            a[i].card[j] = current_str[0];
        }
        if (a[i].identity == 'F') ++fpnum;
        a[i].cardnum = a[i].health = 4;
        a[i].Z = false;
    }

    identity[1] = 'M';
    for (int i = 2; i <= n; ++i)
        identity[i] = 'X';
    for (int i = 1; i <= m; ++i) {
        char current_card[maxn];
        std :: scanf("%s", current_card);
        cards[m - i + 1] = current_card[0];
    }

    round();

    if (a[1].health > 0)
        puts("MP");
    else
        puts("FP");

    for (int i = 1; i <= n; ++i) {
        if (a[i].health <= 0)
            puts("DEAD");
        else {
            for (int j = 1; j <= a[i].cardnum; ++j)
                if (a[i].card[j] != 'X') {
                    putc(a[i].card[j], stdout);
                    putc(' ', stdout);
                }
            putc('\n', stdout);
        }
    }

    return 0;
}