#include<stdio.h>
#include<stdlib.h>
typedef struct edge{
	int src;
	int dest;
	int wt;
}ed;
/*typedef struct node{
	int data;
	struct node* next;
}node;*/
/*typedef struct info{
	int parent;
	int rank;
}info;
*/
long long int rank[500000]={0};
long long int parent[500000]={0};
int compare(const void *a,const void *b)
{
		return ( *(int*)a - *(int*)b );
}
int edge[500000][3];
//info array[500000];
long long int find(long long int a)
{
	if(parent[a]!=a)
		parent[a]=find(parent[a]);
	return parent[a];
}


void findunion(long long int a,long long int b)
{
	long long int x=find(a);
	long long int y=find(b);
	if(rank[x]<rank[y])
		parent[x]=y;
	else if(rank[x] > rank[y]) 
		parent[y]=x;
	else
	{
		parent[y]=x;
		rank[x]++;
	}
	return;
	
}
int main()
{
	long long int testcases,v,e,st,end,c;
	long long int i,j,k,l,sum=0,u,w,min;
	scanf("%lld",&testcases);
	while(testcases--)
	{
		sum=0;
		min=0;
		scanf("%lld%lld",&v,&e);
		for(i=0;i<=v;i++)
		{
		//	array[i].parent=i;
		//	array[i].rank=0;
			parent[i]=0;
			rank[i]=0;
		}
		for(i=0;i<e;i++)
		{
			scanf("%lld%lld%lld",&st,&end,&c);
			sum+=c;
			edge[i][0]=c;
			edge[i][1]=st;
			edge[i][2]=end;
		/*	travel=ptr[st];
			temp=(node*)malloc(sizeof(node));
			temp->data=end;
			temp->next=NULL;
			if(travel==NULL)
				ptr[st]=temp;
			else
			{
				while(travel->next!=NULL)
					travel=travel->next;
				travel->next=temp;
			}*/
		}
		qsort(edge,e,sizeof(int)*3,compare);
/*		printf("check\n");
		for(j=0;j<e;j++)
			printf("%d %d %d\n",edge[j][1],edge[j][2],edge[j][0]);
		*/
		/*for(j=1;j<=v-1;j++)
		{
			u=find(edge[j][1]);
			w=find(edge[j][2]);
			if(findunion(u,w))
			{
			min+=edge[j][0];
			}
		}
		*/
		for(i=0;i<v;i++)
			parent[i]=i;
		int l=0,m=0,n=0;
		min=0;
		while(l<v-1)
		{
			m=n++;
			u=find(edge[m][1]);
			w=find(edge[m][2]);
			//printf("%d %d\n",u,w);
//			printf("cc %d %d\n",edge[m][1],edge[m][2]);
			if(u!=w)
			{
				l++;
//				printf("added %d %d\n",edge[m][1],edge[m][2]);
				min+=edge[m][0];
				findunion(u,w);
			}
		}

//		printf("%lld %lld\n",sum,min);
		printf("%lld\n",sum-min);
	}
	return 0;
}
