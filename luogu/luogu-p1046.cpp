#include <cstdio>
int height[11],h,s;
int main()
{
    for(int i=0;i<10;i++) scanf("%d",&height[i]);
    scanf("%d",&h);
    h+=30;
    for(int i=0;i<10;i++) s+=!(h<height[i]);
    printf("%d",s);
    return 0;
}