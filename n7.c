#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	int weight;
	struct node* next;
}node;

node* ptr[10006];
int vis[100006]={0};
int dfs(int v)
{
	int max=0,sum;
	vis[v]=1;
	node* curr=ptr[v]->next;
	if(curr==NULL)
		return 0;
	while(curr!=NULL)
	{
		if(vis[curr->data]==0)
		{
			vis[curr->data]=1;
			sum=curr->weight+dfs(curr->data);
	//	printf("%d\n",sum);
			if(sum>max)
			max=sum;}
		curr=curr->next;
	}
	return max;
}

int main()
{
	int i,j,k,l,m;
	int testcases,st,end,cost;
	node* travel;
	scanf("%d",&testcases);
	for(j=1;j<=testcases+1;j++)
	{
		ptr[j]=(node*)malloc(sizeof(node));
		ptr[j]->data=0;
		ptr[j]->weight=0;
		ptr[j]->next=NULL;
		vis[j]=0;
	}
	int weightsum=0;
	for(i=1;i<=testcases-1;i++)
	{
		scanf("%d%d%d",&st,&end,&cost);
		weightsum+=cost;
		travel=ptr[st];
		while(travel->next!=NULL)
			travel=travel->next;
		travel->next=(node*)malloc(sizeof(node));
		travel=travel->next;
		travel->data=end;
		travel->weight=cost;
		travel->next=NULL;
		travel=ptr[end];
		while(travel->next!=NULL)
			travel=travel->next;
		travel->next=(node*)malloc(sizeof(node));
		travel=travel->next;
		travel->data=st;
		travel->weight=cost;
		travel->next=NULL;
	}
	int ans;
		ans=dfs(1);
	int res=2*weightsum-ans;
	printf("%d\n",res);
	return 0;
}


