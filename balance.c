#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,k,len,point,flag;
	int testcases;
	char string[200000];
	char stack[200000];
	scanf("%d",&testcases);
	for(i=1;i<=testcases;i++)
	{
		scanf("%s",string);
		len=strlen(string);
		flag=0;
		point=-1;
		for(j=0;j<len;j++)
		{
			if(string[j]=='('||string[j]=='['||string[j]=='{')
			{
				point+=1;
				stack[point]=string[j];
			}
			else if((stack[point]=='('&&string[j]==')')||(stack[point]=='{'&&string[j]=='}')||(stack[point]=='['&&string[j]==']'))
			{
				point--;
			}
			else if((string[j]==']'&&stack[point]!='[')||(string[j]==')'&&stack[point]!='(')||(string[j]=='}'&&stack[point]!='{'))
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
			printf("No\n");
		else if(point==-1)
			printf("Yes\n");
		else if(flag==0 && point!=-1)
			printf("No\n");
	}
	return 0;
}
