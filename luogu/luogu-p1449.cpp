/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-03-07 12:31:18 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-03-08 15:03:08
 */
#include <iostream>
#include <cstdio>
#include <stack>

const int maxn = 1005;
int s[maxn];
int top;
long long num;

int main() {
    char ch;
    ch = getchar();
    while(ch != '@') {
        if(ch >= '0' && ch <= '9') num = num * 10 + ch - '0';
        if(ch == '.') {
            s[++top] = num;
            num = 0;
        }
        switch(ch) {
            case '+': s[top - 1] += s[top];break;
            case '-': s[top - 1] -= s[top];break;
            case '*': s[top - 1] *= s[top];break;
            case '/': s[top - 1] /= s[top];break;
        }

        if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
            top--;

        ch = getchar();
    }
    printf("%d\n",s[1]);
    return 0;
}