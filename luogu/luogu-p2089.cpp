#include <iostream>
using namespace std;
int n,x;
int main()
{
    cin>>n;
    for(int a=1;a<4;a++)
        for(int b=1;b<4;b++)
            for(int c=1;c<4;c++)
                for(int d=1;d<4;d++)
                    for(int e=1;e<4;e++)
                        for(int f=1;f<4;f++)
                            for(int g=1;g<4;g++)
                                for(int h=1;h<4;h++)
                                    for(int i=1;i<4;i++)
                                        for(int j=1;j<4;j++)
                                            if(a+b+c+d+e+f+g+h+i+j==n)
                                                x++;
    cout<<x<<endl;
    for(int a=1;a<4;a++)
        for(int b=1;b<4;b++)
            for(int c=1;c<4;c++)
                for(int d=1;d<4;d++)
                    for(int e=1;e<4;e++)
                        for(int f=1;f<4;f++)
                            for(int g=1;g<4;g++)
                                for(int h=1;h<4;h++)
                                    for(int i=1;i<4;i++)
                                        for(int j=1;j<4;j++)
                                            if(a+b+c+d+e+f+g+h+i+j==n)
                                            {
                                                cout<<a<<" ";
                                                cout<<b<<" ";
                                                cout<<c<<" ";
                                                cout<<d<<" ";
                                                cout<<e<<" ";
                                                cout<<f<<" ";
                                                cout<<g<<" ";
                                                cout<<h<<" ";
                                                cout<<i<<" ";
                                                cout<<j<<" ";
                                                cout<<endl;
                                            }
    return 0;
}