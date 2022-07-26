/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-02-19 11:32:51 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-02-20 01:44:49
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <cstdlib>
using namespace std;

const int maxn = 15;

struct node{
    string str;
    int step;
};

string a, b;
string rulea[maxn];
string ruleb[maxn];
int rules = 1;

void bfs() {
    queue<node> q;
    node now;
    now.str = a;
    now.step = 0;
    q.push(now);

    while (!q.empty()) {
        now = q.front();
        q.pop();
        for (int i = 1; i <= rules; i++) {
            int pos = now.str.find(rulea[i], 0);
            while (1) {
                if (pos == string::npos)
                    break;
                node nxt;
                nxt.str = now.str;
                nxt.str.replace(pos, rulea[i].size(), ruleb[i]);
                nxt.step = now.step + 1;
                if (nxt.str == b) {
                    printf("%d\n", nxt.step);
                    exit(0);
                }
                if (nxt.step > 10) {
                    printf("NO ANSWER!\n");
                    exit(0);
                }
                pos = now.str.find(rulea[i], pos + 1);
                q.push(nxt);
            }
        }
    }
    printf("NO ANSWER!\n");
    return;
}

int main() {
    cin >> a >> b;
    while (cin >> rulea[rules] && cin >> ruleb[rules])
        rules++;
    rules--;
    bfs();
    return 0;
}