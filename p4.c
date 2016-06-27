#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	int data;
	struct node* next;
}node;
int vis[500]={0};
int stack[500]={0};
node* ptr[500];
char array[500][500];
int dfs(int i)
{
	node* curr;
	if(vis[i]==0)
	{
		stack[i]=1;
		vis[i]=1;
		curr=ptr[i];
		while(curr!=NULL)
		{
			if(vis[curr->data]==0 && dfs(curr->data)==1)
			{
			//	printf("curr data %d true1\n",curr->data);
				return 1;
			}
			else if(stack[curr->data]==1)
			{
	//			printf("%d currdata true2\n",curr->data);
				return 1;
			}
			curr=curr->next;
		}
	}
	stack[i]=0;
	return 0;
}	
int isCyclic()
{
	int i;
	for(i=1;i<=26;i++)
		if(dfs(i)==1)
		return 1;
	return 0;
}
int main()
{
	int testcases,number,ans,flag;
	int i,j,k,l,mi,st,end,len1,len2;
	node* temp;
	node* travel;
	scanf("%d",&testcases);
	while(testcases--)
	{
		flag=0;
		scanf("%d",&number);
		for(j=1;j<=26;j++)
		{
			ptr[j]=NULL;
			stack[j]=0;
			vis[j]=0;
		}
		for(i=0;i<number;i++)
		scanf("%s",array[i]);
		/*for(j=0;j<number;j++)
		printf("%s\n",array[j]);*/
		
		for(j=0;j+1<number;j++)
		{
			k=0;l=0;
			len1=strlen(array[j]);
			len2=strlen(array[j+1]);
			while(array[j][k]==array[j+1][l])
			{
	//			printf("%c %c\n",array[j][k],array[j+1][l]);
				k++;l++;
			}
			st=array[j][k]-'a'+1;
			end=array[j+1][l]-'a'+1;
			//printf("%d %d\n",st,end);
			if(end<1 || end>26)
			{
				flag=2;
				break;
			}
			travel=ptr[st];
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
			}
		}
		
/*		for(k=1;k<=26;k++)
		{
			temp=ptr[k];
			while(temp!=NULL)
			{
				printf("%d for %d\n",k,temp->data);
				temp=temp->next;
			}
		}		
*/	
		ans=isCyclic();
//		printf("ans is %d\n",ans);
		if(ans==1 || flag==2)
		printf("Impossible\n");
		else
		printf("Possible\n");					
	}
return 0;
}	
