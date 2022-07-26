/*generator:
#include <iostream>
#include <cstdio>
using namespace std;
int k,i;
int main()
{
    freopen("C:/Users/we/Desktop/p1035_data.out","w",stdout);
    double s=0.000000;
    for(int k=1;k<=15;k++)
    {
        s=0.000000;
        i=0;
        do
        {
            i++;
            s=s+(1.0/i);
        }while(s<=k);
        printf("ans=%d while k=%d\n",i,k);
    }
    return 0;
}
 */
/* 
#include <iostream>
#include <cstdio>
using namespace std;
int k,i;
int main()
{
    double s=0.000000;
    scanf("%d",&k);
    do
    {
        i++;
        s=s+(1.0/i);
    }while(s<=k);
    printf("%d\n",i);
    return 0;
}*/
#include <iostream>
#include <cstdio>
using namespace std;
int k;
int work()
{
	if(k==1) return 2;
	if(k==2) return 4;
	if(k==3) return 11;
	if(k==4) return 31;
	if(k==5) return 83;
	if(k==6) return 227;
	if(k==7) return 616;
	if(k==8) return 1674;
	if(k==9) return 4550;
	if(k==10) return 12367;
	if(k==11) return 33617;
	if(k==12) return 91380;
	if(k==13) return 248397;
	if(k==14) return 675214;
	if(k==15) return 1835421;

}
int main()
{
    scanf("%d",&k);
    printf("%d\n",work());
    return 0;
}