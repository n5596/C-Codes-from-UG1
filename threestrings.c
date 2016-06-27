#include<stdio.h>
#include<string.h>
int front=0,back=0;
int flag=0;
int final;
char concat[300001];
int length1,length2;
int compare(char *a,char *b,int len1,int len2)
{
	int j,k;
	int front=0,back=0,index=0;
	int common,newlength=0;
	while((front<len1 && back<len1) && index<len2)
	{
		if(a[front]==b[index])
		{
			front++;
			index++;
	
		}
		else
		{
			back++;
			front=back;
			index=0;
		}

	}
	common=front-back;
	newlength=common;
//	if(flag==0)
		for(j=0;j<300001;j++)
			concat[j]='\0';
//	{
		for(j=0;j<len1;j++)
			concat[j]=a[j];
		for(k=common;k<len2;k++)
			concat[j++]=b[k];
		
	return newlength;
}
int permutation(char *a,char *b, char *c,int len1,int len2,int len3)
{
	length1=compare(a,b,len1,len2);
	final=strlen(concat);
	//if(final==len1+len2-length1)
	//	printf("length1:%d\n",length1);
	length2=compare(concat,c,final,len3);
	return final+len3-length2;
	
}

int main()
{
	int i,j,k,l,m,s;
	int minlength,len1,len2,len3;
	int lengths[7]={0};
	char first[100001];
	char second[100001];
	char third[100001];
	scanf("%s",first);
	scanf("%s",second);
	scanf("%s",third);
	for(s=0;s<1;s++){
	len1=strlen(first);
	len2=strlen(second);
	len3=strlen(third);}
	/*for(j=0;j<len1;j++)
		printf("%c ",first[j]);
	printf("\n");
	for(j=0;j<len2;j++)
		printf("%c ",second[j]);
	printf("\n");
	for(j=0;j<len3;j++)
		printf("%c ",third[j]);*/
	lengths[0]=permutation(first,second,third,len1,len2,len3);
	lengths[1]=permutation(first,third,second,len1,len3,len2);
	lengths[2]=permutation(second,first,third,len2,len1,len3);
	lengths[3]=permutation(second,third,first,len2,len3,len1);
	lengths[4]=permutation(third,first,second,len3,len1,len2);
	lengths[5]=permutation(third,second,first,len3,len2,len1);
	minlength=100000;
	for(i=0;i<6;i++)
	{
		if(minlength>lengths[i])
			minlength=lengths[i];
	}
	printf("%d\n",minlength);
	/*for(l=0;l<6;l++)
		printf("%d ",lengths[l]);*/
	return 0;
}
