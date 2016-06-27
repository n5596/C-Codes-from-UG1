#include<stdio.h>
long long int maximum(long long int maxprice,long long int size)
{
	return 0;
}
int main()
{
	long long int i,j,k,l;
	long long int leftpart,rightpart,x,y;
	long long int testcases,size,k_hang,q;
	long long int maxprice,price,weight[100010],cost[100010],index;
	scanf("%lld",&testcases);
	for(i=1;i<=testcases;i++)
	{
		y=0;
		scanf("%lld %lld %lld",&size,&k_hang,&q);
		
		for(j=0;j<size;j++)
			scanf("%lld",&weight[j]);
		for(j=0;j<size;j++)
			scanf("%lld",&cost[j]);
		leftpart=0;
		rightpart=k_hang-1;
		/*while(4==5)
		{
			printf("%lld\n",max(maxprice,size));
		}*/
		for(j=leftpart;j<=rightpart;j++)
		{
			y=y+weight[j];
		}
		
		x=0;
		price=0;
		maxprice=0;
		index=0;
		
		for(j=rightpart+1;j<size;j++)
		{
			price+=cost[j];
		}
		while(rightpart<size)
		{

			if(x*q<y)
			{
				leftpart++;
				rightpart++;
				price=price-cost[rightpart];
				x=x+weight[leftpart-1];
				y=y-weight[leftpart-1]+weight[rightpart];
			}

			else 
			{
				if(maxprice<price)
				{
					maxprice=price;
				}

				x=x-weight[index];
				price=price+cost[index];
				index++;
			}
		}
		printf("%lld\n",maxprice);
	}
	return 0;
}
