#include<iostream>
using namespace std;

int main()
{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];

	int min_left[n];
	int max_right[n];

	min_left[0]=0;
	max_right[n-1]=n-1;

	int mine=arr[0],maxe=arr[n-1];

	for(i=1;i<n;i++)
		if(arr[i]<mine)
			mine=arr[i],min_left[i]=i;
		else
			min_left[i]=min_left[i-1];

	for(i=n-2;i>=0;i--)
		if(arr[i]>maxe)
			maxe=arr[i],max_right[i]=i;
		else
			max_right[i]=max_right[i+1];

	int i1=0,i2=0;

	int diff=-1;
	while(i1<=n-1 && i2<=n-1)
	{
		if(arr[min_left[i1]]<arr[max_right[i2]])
			diff=max_right[i2]-min_left[i1],
			i2++;
		else
			i1++;
	}

	cout<<diff<<endl;

	return 0;
}


