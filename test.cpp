#include<stdio.h>
#include<algorithm>
using namespace std;
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
//int i;
	for(i=l;i<=r;i++)
		printf("%d ",arr[i]);

	printf("\n");
}


void mergesort(int a[],int start,int end)
{

	if(end-start<=2)
	{
		/*t i,j,temp;
		for(i=start;i<=end-start;i++)
		{
			for(j=i+1;j<=end;j++)
			{
				if(a[j]<a[j-1])
				{
					temp=a[j];
					a[j]=a[j-1];
					a[j-1]=temp;
				}
			}
		}
		*/
		int i;
		for(i=start;i<=end;i++)
			printf("%d ",a[i]);

		printf("\n");
		sort(a+start,a+end);
		return;
	}
	if(start<end)
	{
		
		printf("%d %d\n",start,end);		
		int mid=(start+end)/3;
		mergesort(a,start,mid);
		mergesort(a,mid+1,end);
		merge(a,start,mid,end);

	}
}
int main()
{
	int n,i,j;
	scanf("%d",&n);

	int a[n];

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	mergesort(a,0,n-1);


	/*	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	 */
	return 0;
}
