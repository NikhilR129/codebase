#include<iostream>
#include<cstdlib>
using namespace std;
int _sum(int bit[],int n,int l)
{
	int sum=bit[l+1];
	l++;
	while(true)
	{
		l-=l&-l;
		if(l<=0) break;
		sum+=bit[l];
	}
	return sum;
}

int main()
{
	int n,i;
	cin>>n;
	int a[n];
	int *bit=(int *)malloc(sizeof(int)*(n+1));
	for(i=0;i<n;i++)
		cin>>a[i];

	bit[0]=0;

	for(i=1;i<=n;i++)
	{
		bit[i]+=a[i-1];
		int idx=i;
		while(true)
		{
			idx+=idx&-idx;
			if(idx>=n)
				break;
			bit[idx]+=a[i-1];
		}
	}

	for(i=0;i<=n;i++)
		cout<<bit[i]<<" ";

	cout<<endl;
	int x;
	while(true)
	{
		cin>>x;
		cout<<_sum(bit,n,x)<<endl;
	}


	return 0;
}


