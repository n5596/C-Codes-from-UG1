#include<stdio.h>
#include<stdlib.h>
#define B 10000010
#define L 500001
long long int flag,front,rear,queue[L],vis[L];
struct city{
	long long int data;
	struct city* next;
};
struct point
{	
	long long int vertex;
	struct city* head;
};

struct point array1[L];
struct point array2[L];
long long int process[L], level[L],sieve[B], primes[L], in[L];


void bfs(long long int u)
{

	long long int val;
        struct city* curr;
	queue[++rear]=u;
	while(front <=rear)
	{
		val=queue[front++];

	if(array1[val].head != NULL)
	{
		curr = array1[val].head;
		while(curr!= NULL)
		{
			if(level[curr->data] < level[val]+1)
				level[curr->data]=level[val]+1;

			if(in[curr->data] == 1)
			{
				queue[++rear]=curr->data;
			}
			else
				in[curr->data]=in[curr->data]-1;
			curr=curr->next;
		}
		
	}
	}

}

void insert(long long int a, long long int b,struct point array[])
{
	struct city* new;
	struct city* prev;
	new=(struct city*)malloc(sizeof(struct city));
	if(array[b].head == NULL)
	{
		array[b].head=new;
		new->data=a;
		new->next=NULL;
	}
	else
	{
		new->data=a;
		prev=array[b].head;
		array[b].head=new;
		new->next=prev;
	}
}

void dfs(long long int u)
{
	vis[u]=1;
	process[u]=1;
	struct city* curr;
	if(array1[u].head != NULL)
	{

		curr = array1[u].head;
		while(curr!= NULL)
		{
			if(process[curr->data] == 1)
			{
				flag=1;
				return;
			}

			else if(vis[curr->data] == 0)
			{

				if( process[curr->data] == 0)
					dfs(curr->data);
				}
			curr=curr->next;
		}
	}
	process[u] = 2;
}


int main()
{
	long long int i,j,k,pos=1;
	long long int testcases,st,end,cities,edges,index=2,sum;
	for(i=2; i<B; i++)
	{
		sieve[i] = 1;
	}
	for(i=2; i<3500; i++)
	{
		if(sieve[i] ==1)
		{
			for(j=i*i; j<B; j=j+i)
			{
				sieve[j] = 0;
			}
		}
	}
	pos=1;index=2;
	while(pos<=500000)
	{

		if(sieve[index] == 1)
		{
			primes[pos] = index;
			pos++;
		}
		index++;
	}
	//printf("hi1\n");
	scanf("%lld",&testcases);	
	for(i=1; i<=testcases; i++)
	{
		primes[0]=0;
		sum=0;
		flag=0;
		scanf("%lld%lld", &cities, &edges);
		for(j=0; j<=cities; j++)
		{
			level[j]=0;
			process[j] = 0;
			vis[j]=0;
			in[j]=0;
			array1[j].head=NULL;
			array2[j].head=NULL;
		}
	//	printf("hi2\n");	
		for(j=1; j<=edges; j++)
		{
			scanf("%lld%lld",&st,&end);
			insert(st,end,array1);
			insert(end,st,array2);
			in[st]++;
		}
		dfs(0);
		//printf("hi3\n");
		if(flag == 1)
			printf("evil emperor loses\n");
		else if(flag == 0)
		{
		//	printf("hi4\n");

			for(k=0; k<cities; k++)
			{
				front=0;
				rear=-1;
				if(array2[k].head == NULL)
				{
 
					bfs(k);
				}
			}
			//printf("hi6\n");
			for(k=0; k<cities; k++)
			{

				sum+=primes[level[k]];

			}
			printf("%lld\n",sum);
		}
	}
	return 0;
}	
