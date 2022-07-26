/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 22:33:19 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 22:33:19 
 */
#include <iostream>
#include <cstdio>
using namespace std;
int a[9]={220,1184,2620,5020,6232,10744,12285,17296,63020}; 
int b[9]={284,1210,2924,5564,6368,10856,14595,18416,76084};
int n;
int main()
{
    cin>>n;
    for(int i=0;i<9;i++)   
    {
        if(a[i]>=n)  
        {
            cout<<a[i]<<' '<<b[i];
            return 0;
        }
        if(b[i]>n)
        {
            cout<<b[i]<<' '<<a[i];         
            return 0;
        }
    }
    return 0;
}