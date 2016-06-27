#include<stdio.h>
#include<math.h>
#include<string.h>
long long int power(long long int a,long long int b)
{
	long long int res=1;
	if(b==0)
		return 1;
	while(b!=0)
	{
		if(b%2==1)
			res=(res*a)%1000000007;
	a=(a*a)%1000000007;
	b/=2;
	}
	return res;
}
int main()
{
	long long int i,j,k,l;
	long long int testcases,len,top,a1,a2;
	long long int mod=1000000007;
	char string[200000];
	long long int stack[200000]={0};
	scanf("%lld",&testcases);
	for(i=1;i<=testcases;i++)
	{
		top=-1;
		scanf("%s",string);
		len=strlen(string);
		for(j=0;j<len;j++)
		{
			if(string[j]!='+' && string[j]!='-' && string[j]!='*' && string[j]!='/')
				{
					//printf("%d %c\n",(int)string[j]-'0',string[j]);
					top++;
					stack[top]=(int)string[j]-'0';
					//printf("in the stack%d\n",stack[top]);
				}
			else
			{
				a2=stack[top--];
				a1=stack[top--];
			if(string[j]=='+')
				stack[++top]=((a1%mod)+(a2%mod))%mod;
			else if(string[j]=='-')
				stack[++top]=((a1%mod)-(a2%mod)+mod)%mod;
			else if(string[j]=='*')
				stack[++top]=((a1%mod)*(a2%mod))%mod;
			else if(string[j]=='/')
				stack[++top]=((a1%mod)*(power(a2,mod-2)))%mod;
			}
		}
		printf("%lld\n",stack[top]);
	}
	return 0;
}
