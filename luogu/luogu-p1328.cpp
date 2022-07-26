#include <iostream>
using namespace std;
int n,na,nb,a[210],b[210],ansa,ansb;
int score[5][5]={{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
int main()
{
    cin>>n>>na>>nb;
    for(int i=0;i<na;i++) cin>>a[i];
    for(int i=0;i<nb;i++) cin>>b[i];
    for(int i=0;i<n;i++)
    {
        ansa+=score[a[i%na]][b[i%nb]]; 
        ansb+=score[b[i%nb]][a[i%na]];
    }
    cout<<ansa<<" "<<ansb<<endl;
    return 0;
}