#include<stdio.h>
long long int array[100000]={0};
long long int hash[100000]={0};
int main()
{
	long long int i,j,k,l;
	long long int mod=1000000007;
	long long int testcases,size,div,sum,count;
	scanf("%lld",&testcases);
	div=0;
	for(i=1;i<=testcases;i++)
	{
		for(j=0;j<div;j++)
			hash[j]=0;
		scanf("%lld%lld",&size,&div);
		for(j=0;j<size;j++)
			scanf("%lld",&array[j]);
		sum=0;
		hash[0]=1;
		for(j=0;j<size;j++)
		{
			sum=(sum+array[j])%div;
		//	printf("%d ",sum%div);
			hash[sum]++;
		}
		/*for(k=0;k<size;k++)
			printf("%d ",hash[k]);*/
	//	printf("Printing hash table\n");
	//	for(j=0;j<div;j++)
	//		printf("%d ",hash[j]);
		count=0;
		for(j=0;j<div;j++)
			count=(count%mod+(hash[j]*(hash[j]-1)/2)%mod)%mod;
		printf("%lld\n",count);
	}
	return 0;
}
