/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 22:39:48 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 22:39:48 
 */
#include <iostream>
using namespace std;
int day,today,miss,score,card;
void ext(int n){if(card>=n) score++;}
int main()
{
    cin>>day;
    while(day--)
    {
        cin>>today;
        if(today)
        {
            if(miss>0) card-=1<<miss-1;
            if(card<0) card=0;
            card++;
            score++;
            miss=0;
            ext(3);ext(7);ext(30);ext(120);ext(365);
        }
        else miss++;
    }
    cout<<score;
    return 0;
}