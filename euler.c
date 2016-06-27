#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int num;
	struct node* next;
}node;
node* ptr[200003];
int vis[100003]={0};
int in[100003]={0};
int out[100003]={0};
void dfs(int u,int vertices)
{
	vis[u]=1;
	node* curr=ptr[u];
	while(curr->next!=NULL)
	{
		if(vis[curr->next->num]==0)
			dfs(curr->next->num,vertices);
		curr=curr->next;
	}
	return;
}

int main()
{
	int i,j,k,l,m;
	int testcases,nodes,edges,st,end,flag;
	node* travel;
	scanf("%d",&testcases);
	for(i=1;i<=testcases;i++)
	{
		scanf("%d%d",&nodes,&edges);	
		for(j=1;j<=nodes;j++)
		{
			ptr[j]=(node*)malloc(sizeof(node));
			ptr[j]->num=0;
			ptr[j]->next=NULL;
		}
		/*for(j=0;j<edges;j++)
		 * 			printf("%p\n",ptr[j]);*/
		for(j=0;j<edges;j++)
		{
			scanf("%d%d",&st,&end);
			in[end]++;
			out[st]++;
			//	printf("%d %d",st,end);
			travel=ptr[st];
			while(travel->next!=NULL)
			{
				travel=travel->next;
			}
			travel->next=(node*)malloc(sizeof(node));
			travel=travel->next;
			travel->num=end;
			travel->next=NULL;
		}
		flag=0;
		/*	travel=ptr[1];
			while(travel->next!=NULL)
			{
			printf("%d\n",travel->num);
			travel=travel->next;
			}
			*/
		for(k=1;k<=nodes;k++)
		{
			if(in[k]!=out[k] || (in[nodes]==0&&out[nodes]==0))
			{
				printf("No\n");
				flag=4;
				break;
			}
			else if(out[k]==0)
			{
				vis[k]=1;
			}
		}
		if(flag!=4)
		{
			//not visited
			dfs(1,nodes);
			for(k=1;k<=nodes;k++)
				if(vis[k]==0)
				{
					flag=1;
					break;
				}
		}
		if(flag==1)
			printf("No\n");
		else if(flag==0)
			printf("Yes\n");
		for(j=1;j<=nodes;j++)
		{
			vis[j]=0; 
			in[j]=0;
			out[j]=0;
		}
	}
	return 0;

}

