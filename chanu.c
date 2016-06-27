#include<stdio.h>
int main()
{
	int i,j,k,l;
	int testcases,jump,number,min,pos,flag,st,end,index;
	int sum[1000000]={0};
	int array[100000]={0};
	scanf("%d",&testcases);
	
	for(i=1;i<=testcases;i++)
	{
		flag=0;
		scanf("%d%d",&number,&jump);
		for(j=0;j<number;j++)
			scanf("%d",&array[j]); //fill the array
		sum[0]=array[0];
		st=0;end=0;pos=0;
		min=sum[0];index=1;
		while(st<=end && end<number)
		{
			if(st<=pos && pos<=end) //minimum is in the window
			{
				if(sum[end]<min)
				{
					min=sum[end];
					pos=end;
				}
				sum[index]=array[index]+min;
			}
			else
			{                    //since minimum is not in window we find the new minimum
				min=sum[st];
				for(k=st;k<=end;k++)
					if(sum[k]<=min)
					{
						pos=k;
						min=sum[k];
					}
				sum[index]=array[index]+min;
			}
			index++;
			if((1+end-st)==jump) //shift the window
				st++;
			end++;
		}
		printf("%d\n",sum[number-1]);
	}
	return 0;
}


