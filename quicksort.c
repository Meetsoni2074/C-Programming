#include<stdio.h>
void quick(int [],int,int);
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
	quick(a,0,n-1);
	printf("\nthe sorted list is under:");
	for(i=0;i<n;i++)
	{
		printf("\n%d",a[i]);
	}
	return 0;
}
void quick(int a[],int l,int h)
{
	int p,i,j,tmp;
	if(l<h)
	{
		p=l;
		i=l;
		j=h;
		while(i<j)
		{
			while(a[i]<=a[p] && i<=h)
			{
				i++;
			}
			while(a[j]>a[p] && j>=l)
			{
				j--;
			}
			if(i<j)
			{
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
		tmp=a[j];
		a[j]=a[p];
		a[p]=tmp;
		quick(a,l,j-1);
		quick(a,j+1,h);
	}
}
