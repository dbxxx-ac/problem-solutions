/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 20:29:03 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 20:29:03 
 */
#include <iostream>
#include <cstdio>
using namespace std; 
struct student
{
	char name[25];
	int final_score;
	int class_score;
	char cadre;
	char west;
	int essays;
	int scholarship; 
}a[105];

int n;
int best,sum;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%s %d %d %c %c %d",a[i].name,&a[i].final_score,&a[i].class_score,&a[i].cadre,&a[i].west,&a[i].essays);
	for(int i=1;i<=n;i++)
	{
		if(a[i].final_score>80&&a[i].essays) a[i].scholarship+=8000;
		if(a[i].final_score>85&&a[i].class_score>80) a[i].scholarship+=4000;
		if(a[i].final_score>90) a[i].scholarship+=2000;
		if(a[i].west=='Y'&&a[i].final_score>85) a[i].scholarship+=1000;
		if(a[i].cadre=='Y'&&a[i].class_score>80) a[i].scholarship+=850;
		if(a[i].scholarship>a[best].scholarship)
			best=i;
		sum+=a[i].scholarship;
	}
	printf("%s\n%d\n%d\n",a[best].name,a[best].scholarship,sum);
	return 0;
}
