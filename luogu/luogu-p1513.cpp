/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 20:29:49 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-01-10 22:00:14
 */
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

struct pail
{
	double x,y;
}a[105];

int n;
double r;
double ans;
const double pi=acos(-1);

double dis(double x1,double x2,double y1,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
	scanf("%d%lf",&n,&r);
	for(int i=0;i<n;i++)
		scanf("%lf%lf",&a[i].x,&a[i].y);
	for(int i=1;i<n;i++)
		ans+=dis(a[i].x,a[i-1].x,a[i].y,a[i-1].y);
	ans+=dis(a[0].x,a[n-1].x,a[0].y,a[n-1].y)+pi*2*r;
	printf("%.2lf\n",ans);
	return 0;
}
