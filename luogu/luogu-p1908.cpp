#include <cstdio>
int a[500005];
int a1[500005];
long long num,n;

void merge(int start,int mid,int end)
{
    int k=start,k1=start,k2=mid+1;
    while(k1<=mid&&k2<=end)
    {
        if(a[k1]<=a[k2])
            a1[k++]=a[k1++];
        else
        {
            a1[k++]=a[k2++];
            num+=mid+1-k1;
        }
    }
    while(k1<=mid)
        a1[k++]=a[k1++];
    while(k2<=end)
        a1[k++]=a[k2++];
    for(int i=start;i<=end;i++)
        a[i]=a1[i];
}

void merge_sort(int l,int r)
{
    if(l==r) return ;
    int mid=(l+r)/2;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    merge(l,mid,r);
}

int main()
{
    int i;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    merge_sort(1,n);
    printf("%lld",num);
    return 0;
}
