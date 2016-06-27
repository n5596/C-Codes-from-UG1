#include<stdio.h>
typedef struct item{
	int start;
	int end;
	int mokoval;
}item;
int array[1000006][3];
int times[1000006]={0};
int compare(const void *a,const void *b)
{
	return ( *(int*)a - *(int*)b );
}
int jump[1000006]={0};
int main()
{
	int i,j,k,l,m;
	int testcases,number,li,ri,vi;
	scanf("%d",&testcases);
	for(i=1;i<=testcases;i++)
	{
		int max=0;
		scanf("%d",&number);
		for(j=0;j<1000006;j++){
			jump[j]=0;
			times[j]=0;
		}
		for(j=0;j<number;j++)
		{
			//	jump[j]=0;
			scanf("%d%d%d",&array[j][1],&array[j][2],&array[j][0]);
			//if(array[j][2]>max)
			//	max=array[j][2];
		}
		qsort(array,number,sizeof(int)*3,compare);
		/*		printf("List after\n");
				for(k=0;k<number;k++)
				printf("%d %d %d\n",array[k][1],array[k][2],array[k][0]);*/
		/*	printf("hii\n");
			for(k=0;k<=max;k++)
			printf("%d ",times[k]);
			printf("\n");*/
		for(j=number-1;j>=0;j--)
		{
			k=array[j][1];
			while(k<array[j][2])//for(k=array[j][1];k<array[j][2];k++)
			{
				//printf("k is %d\n",k);
				if(times[k]==0)
				{
					times[k]=array[j][0];
					jump[k]=array[j][2];
					k++;
				}
				else if(jump[k]!=0)
					k=jump[k];
				else
					k++;

			}

		}
		//printf("hell %d\n",max);

		/*		for(k=0;k<=max;k++)
				printf("%d ",times[k]);*/
		/*	for(k=1;k<=max;k++)
			if(times[k]!=times[k-1])
			{
			printf("%d %d\n",k,times[k]);
			}*/
		j=1;
		/*	for(k=0;k<=max;k++)
			printf("%d ",jump[k]);*/
		int flag=0;
/*		while(j<=1000006)
		{
			if(jump[j]!=0 && times[j]!=times[j-1])
			{
			//	printf("%d %d\n",j,times[j]);
				j++;

			}
			else if(jump[j]==0)
				j++;
			else
			{
				j=jump[j];
			}
			//	printf("j is %d\n",j);

		}
		//for(k=0;k<=max;k++)
		//	times[k]=0;*/
		for(k=1;k<1000006;k++)
			if(times[k]!=times[k-1])
				printf("%d %d\n",k,times[k]);
	}
	return 0;
}
