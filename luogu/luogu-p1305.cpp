//忘加水印啦~qwq
#include <iostream>
#include <cstdio>

std :: string s[35];
int n;
char root;

void work(char ch) {
    if(ch == '*') return ;
    std :: cout << ch;
    for(int i = 1; i <= n; i++)
        if(s[i][0] == ch) {
            work(s[i][1]);
            work(s[i][2]);
        }
}

int main() {
    std :: cin >> n;
    for(int i = 1; i <= n; i++) {
        std :: cin >> s[i];
        for(int j = 0; j < 3; j++)
            if(s[i][j] != '*')
                root ^= s[i][j];
    }
    work(root);
    return 0;
}
