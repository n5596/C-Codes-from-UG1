#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* next;
}node;
node* ptr[1000008];
int vis[1000008]={0};
long long int array[1000008]={0};

long long int mod=1000000007;

long long int sum(int n)
{
	long long int i,sum=0;
	for(i=1;i<=n;i++)
		sum+=array[i];
	return sum;
}
long long int subtrees(int v)
{
	if(array[v]!=0)
		return array[v];
	node* travel=ptr[v]->next;
	long long int a=1;
	if(travel==NULL)
	{
		array[v]=1;
		//             printf("returning 1\n");
		return 1;
	}
	else
	{
		while(travel!=NULL)
		{
			a=(a*(subtrees(travel->data)+1))%mod;
			travel=travel->next;
		}   
		array[v]=a;
		return array[v];
	}
}	
int main()
{
	int i,j,k,l;
	int testcases,nodes,st,end;
	node* travel;
	scanf("%d",&testcases);
	for(i=1;i<=testcases;i++)
	{
		scanf("%d",&nodes);
		for(j=1;j<=nodes;j++)
		{
			ptr[j]=(node*)malloc(sizeof(node));
			ptr[j]->data=0;
			ptr[j]->next=NULL;
			vis[j]=0;
			array[j]=0;
		}
		for(j=1;j<=nodes-1;j++)
		{
			scanf("%d%d",&st,&end);
			travel=ptr[st];
			while(travel->next!=NULL)
				travel=travel->next;
			travel->next=(node*)malloc(sizeof(node));
			travel=travel->next;
			travel->data=end;
			travel->next=NULL;
		}
		travel=ptr[1];
		long long int res=0;
		for(l=1;l<=nodes;l++)
			res+=subtrees(l);
		res=sum(nodes);
		//for(l=1;l<=nodes;l++)
		//	printf("index %d has %d\n",l,array[l]);
		//int res=sum(nodes);
		printf("%lld\n",res%mod);
	}
	return 0;
}

