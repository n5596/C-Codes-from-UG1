#include<stdio.h>
int main()
{
	int i,j,k,l,m;
	int testcases,size,top=-1,interval;
	int array[100000]={0};
	int leftpart[100000]={0};
	int rightpart[100000]={0};
	int stack[100000]={0};
	scanf("%d",&testcases);
	for(i=1;i<=testcases;i++)
	{
		scanf("%d",&size);
		for(j=0;j<size;j++)
			scanf("%d",&array[j]); //scan the entire array
		for(k=0;k<size;k++)
		{
			leftpart[k]=-1;
			rightpart[k]=size;
		}
		for(k=0;k<size-1;k++)
		{
			for(l=k+1;l<size;l++)
			{
				if(array[l]<array[k])
				{
					rightpart[k]=l;
					break;
				}
			}
		}
		for(k=1;k<size;k++)
		{
			l=k-1;
			while(l>=0)
			{if(array[l]<array[k])
				{
					leftpart[k]=l;
					break;
				}
				l--;
			}
	
		}
		int final[size+1];
		for(j=0;j<size+1;j++)
			final[j]=0;
		for(j=0;j<size;j++)
		{
			interval=rightpart[j]-leftpart[j]-1;
			if(final[interval]<array[j])
				final[interval]=array[j];
		}
		for(k=size-1;k>=0;k--)
			if(final[k+1]>final[k])
				final[k]=final[k+1];
		for(k=1;k<=size-1;k++)
			printf("%d ",final[k]);
		printf("%d\n",final[size]);
		/*printf("left");
		for(k=0;k<size;k++)
			printf("%d ",leftpart[k]);
		printf("\nright");
		for(k=0;k<size;k++)
			printf("%d ",rightpart[k]);
			*/
	}
	return 0;
}

