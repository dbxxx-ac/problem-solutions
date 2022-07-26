/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 20:29:59 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 20:29:59 
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char lock[35][15]={"one","two","three","four","five","six","seven","eight","nine","ten",
                "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty",
                "a","another","first","both","second","third"};

int keys[35]={1,4,9,16,25,36,49,64,81,0,21,44,69,96,25,56,89,24,61,0,1,1,1,4,4,9};

char s[1005];
bool fnd;
int a[15],ind;

int main()
{
    for(int i=0;i<6;i++)
    {
        scanf("%s",s);
        for(int j=0;j<26;j++)
            if(!strcmp(s,lock[j]))
            {
                fnd=true;
                a[ind++]=keys[j];
                break;
            }
    }

    if(!fnd) 
    {
        puts("0");
        return 0;
    }

    sort(a,a+ind);
    for(int i=0;i<ind;i++)
        if(i) printf("%.2d",a[i]);
        else printf("%d",a[i]);
    
    puts("");
    return 0;
}