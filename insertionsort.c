#include<stdio.h>
int main()
{
	int i,j,tmp,n;
	int arr[10];
	printf("\nenter the number of element:");
	scanf("%d",&n);
	printf("\nenter %d integers\n",n);
	for(i=0;i<n;i++)//5
	{
		scanf("%d",&arr[i]);
	}
	for(i=1;i<n;i++)//1 to 5
	{
		j=i;
		while(j>0 && arr[j-1]>arr[j])//4 5 2 1 3
		{
			tmp=arr[j];
			arr[j]=arr[j-1];
			arr[j-1]=tmp;
			j--;
		}
	}
	printf("\nsorted list in ascending oreder\n");
	for(i=0;i<n;i++)
	{
		printf("\n%d",arr[i]);
	}
	return 0;
}
