#include <cstdio>
int n,a;
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d", &a);
        if(a&1)
            printf("zs wins\n");
        else
            printf("pb wins\n");
    }
    return 0;
}