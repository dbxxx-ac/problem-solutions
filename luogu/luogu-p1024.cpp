/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 20:27:43 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-01-10 20:28:17
 */
#include <iostream>
#include <cstdio>
using namespace std;

double a,b,c,d;
const double exp=1e-4; 

double f(double x)
{
	return a*x*x*x+b*x*x+c*x+d; 
}

int main()
{
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	for(int i=-100;i<100;i++)
	{
		double l=i;
		double r=i+1;
		double xl=f(l);
		double xr=f(r);
		if(xl==0) printf("%.2lf ",l);
		if(xl*xr<0)
		{
			while(r-l>=exp)
			{
				double mid=(l+r)/2;
				if(f(mid)*f(r)<=0) l=mid;
				else r=mid;
			}
			printf("%.2lf ",r);
		}
	}
	return 0;
}
