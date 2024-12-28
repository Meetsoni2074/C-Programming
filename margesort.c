#include<stdio.h>
void margesort(int [],int,int);
void marge(int [],int,int,int,int);
int main()
{
	int i,n,a[30];
	printf("\nenter the number of element:");
	scanf("%d",&n);
	printf("\nenter the element:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	margesort(a,0,n-1);
	printf("\nthe sorted list is under:");
	for(i=0;i<n;i++)
	{
		printf("\n%d",a[i]);
	}
	return 0;
}
void margesort(int a[],int i,int j)
{
	int mid;
	if(i<j)
	{
		mid=(i+j)/2;
		margesort(a,i,mid);
		margesort(a,mid+1,j);
		marge(a,i,mid,mid+1,j);
	}
}
void marge(int a[],int i1,int j1,int i2,int j2)
{
	int tmp[50];
	int i,j,k;
	i=i1;
	j=i2;
	k=0;
	while(i<=j1 && j<=j2)
	{
		if(a[i]<a[j])
		{
			tmp[k++]=a[i++];
		}
		else
		{
			tmp[k++]=a[j++];
		}
	}
	while(i<=j1)
	{
		tmp[k++]=a[i++];
	}
	while(j<=j2)
	{
		tmp[k++]=a[j++];
	}
	for(i=i1,j=0;i<=j2;i++,j++)
	{
			a[i]=tmp[j];
	}
}
