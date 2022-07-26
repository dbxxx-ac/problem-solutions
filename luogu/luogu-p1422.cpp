#include <cstdio>
int main()
{
    double n;
    scanf("%lf",&n);
    if(n<=150)
        printf("%.1lf",n*0.4463);
    else if(n>=151&&n<=400)
        printf("%.1lf",150*0.4463+(n-150)*0.4663);
    else 
        printf("%.1lf",150*0.4463+250*0.4663+(n-400)*0.5663);
    return 0;
}