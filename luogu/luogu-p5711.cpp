/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-18 19:10:47 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-01-18 19:17:09
 */
#include <bits/stdc++.h>
using namespace std;

int y;

int main(){
    scanf("%d",&y);
    if(y%4==0){
        if(y%400==0)
            printf("1\n");
        else if(y%100!=0)
            printf("1\n");
    }
    else
    printf("0\n");
        
    return 0;
}