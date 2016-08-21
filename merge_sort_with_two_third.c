#include<stdio.h>
#include<time.h>
#include<stdlib.h>
/*void merge(int a[],int start,int mid,int end)
  {
  int b[mid-start+1];
  int c[end-mid],i;

  for(i=start;i<=mid;i++)
  b[i-start]=a[i];

  for(i=mid+1;i<=end;i++)
  c[i-mid-1]=a[i];

  int idx1=0,idx2=0;

  int counter=start;

  while(idx1<=mid-start && idx2<=end-mid-1)
  {
  if(b[idx1]<=c[idx2])
  {
  a[counter]=b[idx1];
  idx1++;
  counter++;
  }
  else
  {
  a[counter]=c[idx2];
  idx2++;
  counter++;
  }
  }
  while(idx1<=mid-start)
  a[counter++]=b[idx1++];

  while(idx2<=end-mid-1)
  a[counter++]=c[idx2++];
  for(i=start;i<=end;i++)
  printf("%d ",a[i]);
  printf("\n");
  }
 */

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 =  r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	   are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	   are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}

	for(i=l;i<=r;i++)
		printf("%d ",arr[i]);

	printf("\n");
}

void merge_sort_random(int a[],int start,int end)
{
	if(start<end)
	{
		int temp=rand()%(end-start+1);
		int mid=temp+start;
		merge_sort_random(a,start,mid);
		merge_sort_random(a,mid+1,end);
		merge(a,start,mid,end);
	}
}

void mergesort(int a[],int start,int end,int k)
{

	if(end-start<=(k-2))
	{
		int i,j,temp;
		for(i=start;i<=end;i++)
		{
			for(j=start+1;j<=end;j++)
				if(a[j-1]>a[j])
				{
					temp=a[j-1];
					a[j-1]=a[j];
					a[j]=temp;
				}
		}
		for(i=start;i<=end;i++)
			printf("%d ",a[i]);

		printf("\n");

		return;
	}
	//if(start<end)
	if(end-start>(k-2))
	{
		//printf("%d %d\n",start,end);
		//randomly generate mid for random partition		
		int mid=start+(end-start)/k;
		mergesort(a,start,mid,k);
		mergesort(a,mid+1,end,k);
		merge(a,start,mid,end);

	}
}
int main()
{
	int n,i,j,k;
	srand(time(NULL));
	scanf("%d",&n);
	
	int a[n];

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&k);
	//mergesort(a,0,n-1,k);
	merge_sort_random(a,0,n-1);

	for(i=0;i<n;i++)
		printf("%d ",a[i]);

	return 0;
}
