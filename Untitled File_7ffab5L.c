#include <stdio.h>
char str[10][100000];
char array[100000];
int breaks[1000];
int func(int a)
{
    int i,flag=0,count=0;
    for(i=0;i<a;i++)
    {
        if(array[i]=='.')
        {
            count++;
        }
    }
  //  printf("%d %d\n",count,a);
    if(count==a)
    return 0;
    return 1;
}
int main()
{
    int i,j,k,len,n,m,o;
    int res;
 //   printf("Hello World!\n");
    scanf("%[^\n]s",array);
    len=strlen(array);
    res=func(len);
    m=1;
    while(res!=0)
    {
        strcpy(str[m-1],array);
   //     printf("copied: %s\n",str[m-1]);
        scanf(" %[^\n]s",array);
        len=strlen(array);
        res=func(len);
 //      printf("%s\n",str[m]);
        m++;
    }
    for(i=0;i<m-1;i++)
    {
        printf("%s\n",str[i]);
    }
    for(o=0;o<m-1;o++)
    {
    j=0;
    len=strlen(str[o]);
    for(i=0;i<100;i++)
    breaks[i]=0;
    for(i=0;i<len;i++)
    {
        if(str[o][i]==' ')
        {
            breaks[j++]=i;
        }
    }
  /*    for(i=0;i<j;i++)
      printf("%d ", breaks[i]);*/
     for(k=breaks[0]-1;k>=0;k--)
     printf("%c",str[o][k]);
     printf(" ");
  for(i=1;i<j;i++)
    {
        for(k=breaks[i]-1;k>=breaks[i-1];k--)
        printf("%c",str[o][k]);
    //    printf(" ");
    }
    for(k=len-1;k>=breaks[i-1]+1;k--)
    printf("%c",str[o][k]);
    printf("\n");
  //  printf("rres %d ",res);
 //   printf("res %d %d\n",res,len);
    }
    
    return 0;
}
