#include <stdio.h>
int main()
{
    int i,j,k,max;
    scanf("%d\n",&i);
    scanf("%d\n",&j);
    scanf("%d\n",&k);
    if (i>j)
      max = i;
    else max = j;
    if (k>max)
      max = k;
    printf("%d\n",max);
}