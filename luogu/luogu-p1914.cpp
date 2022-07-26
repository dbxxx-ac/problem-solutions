#include <cstdio>
int main()
{
    char before[55]; 
    int n; 
    scanf("%d%s",&n,before); 
    for(int i=0;before[i]!='\0';i++)
        putchar((before[i]-'a'+n)%26+'a');
    return 0;
}