/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-01-10 20:29:15 
 * @Last Modified by:   crab-in-the-northeast 
 * @Last Modified time: 2020-01-10 20:29:15 
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;

struct student
{
	int score;
	int chinese;
	int school_id;
}a[305];

int math,English;

bool cmp(student a,student b)
{
	if(a.score!=b.score) return a.score>b.score;
	if(a.chinese!=b.chinese) return a.chinese>b.chinese;
	return a.school_id<b.school_id;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&a[i].chinese,&math,&English);
		a[i].score=a[i].chinese+math+English;
		a[i].school_id=i+1;
	}
	sort(a,a+n,cmp);
	for(int i=0;i<5;i++)
		printf("%d %d\n",a[i].school_id,a[i].score);
	return 0;
}
