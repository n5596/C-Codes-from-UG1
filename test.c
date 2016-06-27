#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sorting(const void *a, const void *b)
{
	char arr1[32], arr2[32];
	sprintf(arr1,"%d%d", *(int*)a, *(int*)b);
	sprintf(arr2,"%d%d", *(int*)b, *(int*)a);
	return strcmp(arr2, arr1);
}

int main(void)
{
	int i,j,k;
	int no_elements,length;
	scanf("%d",&no_elements);
	int concat[no_elements];
	for(i=0;i<no_elements;i++)
	scanf("%d",&concat[i]);
	//for(i=0;i<n;i++)
	//	printf("%d ",x[i]);
	length=sizeof(concat)/sizeof(concat[0]);
	qsort(concat,length,sizeof(int),sorting);
	for(i=0;i<length;i++) //concat now a string
		printf("%d",concat[i]);
	printf("\n");
	return 0;
}
