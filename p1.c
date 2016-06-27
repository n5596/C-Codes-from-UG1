#include<stdio.h>
#include<stdlib.h>
long long int cost[400005]={0};
typedef struct node
{
	int data;
	struct node* next;
}node;
long long int mod=1000000007;
long long int ways=0;
long long int p,count;
long long int min=1000000007;
int vis[400005]={0};
long long int times[400005]={0};
node* ptr[400005];
node* transpose[400005];
void dfs(long long int a)
{
	vis[a]=1;
	node* curr=ptr[a];
	while(curr!=NULL)
	{
		if(vis[curr->data]==0)
		dfs(curr->data);
		curr=curr->next;
	}
	times[p++]=a;
	return;
}
void reversedfs(long long int a)
{
	vis[a]=1;
	if(min >= cost[a])
	{min = cost[a];}
//	printf("min is %lld\n",min);
    node* curr=transpose[a];
//	printf("%d\n",a);
	while(curr!=NULL)
	{
		if(vis[curr->data]==0)
		reversedfs(curr->data);
		curr=curr->next;
	}
	if(min == cost[a])
		ways++;
/*	if(min==cost[a])
	ways++;*/
	return;
}
/*void print(int a)
{
printf("original\n");
node* curr=ptr[a];
while(curr!=NULL)
{
printf("%d\n",curr->data);
curr=curr->next;
}
printf("reverse\n");
curr=transpose[a];
while(curr!=NULL)
{
printf("%d\n",curr->data);
curr=curr->next;
}
return;
}*/
void insert(node* travel,int data)
{
node* temp=(node*)malloc(sizeof(node));
temp->data=data;
temp->next=NULL;
 while(travel->next!=NULL)
      travel=travel->next;
	return;
}
int main()
{
	long long int i,j,k,l,m;
	long long int testcases,size,edges,st,end,sum;
	node* travel;
	scanf("%lld",&testcases);
	for(i=1;i<=testcases;i++)
	{
	sum=0;count=1;
		scanf("%lld%lld",&size,&edges);
			for(j=1;j<=size;j++)
			{
				ptr[j]=NULL;
		//		ptr[j]->data=0;
		//		ptr[j]->next=NULL;
				vis[j]=0;
				transpose[j]=NULL;
		//		transpose[j]=(node*)malloc(sizeof(node));
		//		transpose[j]->data=0;
				//transpose[j]->next=NULL;
			}
		
		for(j=1;j<=size;j++)
			scanf("%lld",&cost[j]);
		for(k=1;k<=edges;k++)
		{
			scanf("%lld%lld",&st,&end);
			node* graph=(node*)malloc(sizeof(node));
			node* trans=(node*)malloc(sizeof(node));
			trans->data=st;
			trans->next=NULL;
			graph->data=end;
			graph->next=NULL;
			travel=ptr[st];
			if(travel==NULL)
			{
				ptr[st]=graph;
			}
			else{
			while(travel->next!=NULL)
			travel=travel->next;
			travel->next=graph;}
		/*	travel->next=(node*)malloc(sizeof(node));
			travel=travel->next;
			travel->data=end;
			travel->next=NULL;*/
			travel=transpose[end];
			if(travel==NULL)
			{
				transpose[end]=trans;
			}
			else{
			while(travel->next!=NULL)
			travel=travel->next;
			travel->next=trans;}
			/*while(travel->next!=NULL)
			travel=travel->next;
			travel->next=(node*)malloc(sizeof(node));
			travel=travel->next;
			travel->data=st;
			travel->next=NULL;*/
		}
//		print(1);
		p=1;
		for(k=1;k<=size;k++)
			if(vis[k]==0)
			dfs(k);
		for(k=1;k<=size;k++)
		vis[k]=0;
		for(k=size;k>=1;k--)
		{
//			printf("connected: ");
		if(vis[times[k]]==0)
		{
		min=mod;
		ways=0;
		reversedfs(times[k]);
		sum+=min;
//		printf("ways:%d min %d\n",ways,minimum[0]);
		count=((count%mod)*(ways%mod))%mod;
		}
		}
		printf("%lld %lld\n",sum,count%mod);
	}
		return 0;
}
