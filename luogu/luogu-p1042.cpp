/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-02-01 17:37:45 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-02-01 18:47:19
 */
#include <bits/stdc++.h>
using namespace std;

int w,l;
char c;
string s;

int max(int a,int b){
    return a>b?a:b;
}

int abs(int x){
    return x>0?x:-x;
}

int main(){
    while(~scanf("%c",&c)&&c!='E'){
        if(c=='W'){
            w++;
            s+=c;
        }else if(c=='L'){
            l++;
            s+=c;
        }

        if(max(w,l)>=11&&abs(w-l)>=2){
            printf("%d:%d\n",w,l);
            w=0;
            l=0;
        }
    }    

    printf("%d:%d\n\n",w,l);
    w=0;
    l=0;

    for(int j=0;j<s.length();j++){
        if(s[j]=='W') w++;
        else if(s[j]=='L') l++;
        if(max(w,l)>=21&&abs(w-l)>=2){
            printf("%d:%d\n",w,l);
            w=0;
            l=0;
        }
    }

    printf("%d:%d\n",w,l);
    return 0;
}