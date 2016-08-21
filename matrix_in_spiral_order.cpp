#include<bits/stdc++.h>
using namespace std;
void print_spiral(int **a,int idx1,int idx2,int idx3,int idx4)
{
	if(idx1>=idx3 && idx2>=idx4)
	{
		if(idx1==idx3 && idx2==idx4)
			cout<<a[idx1][idx2]<<" ";
		return ;
	}
	int i;
	for(i=idx2;i<idx4;i++)
		cout<<a[idx1][i]<<" ";

	for(i=idx1;i<idx3;i++)
		cout<<a[i][idx4]<<" ";

	for(i=idx4;i>idx2;i--)
		cout<<a[idx3][i]<<" ";

	for(i=idx3;i>idx1;i--)
		cout<<a[i][idx2]<<" ";

	print_spiral(a,idx1+1,idx2+1,idx3-1,idx4-1);
}


int main()
{
	int n,i,j;
	cin>>n;
	int **a=(int**)malloc(sizeof(int *)*n);

	for(i=0;i<n;i++)
		a[i]=(int *)malloc(sizeof(int)*n);

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>a[i][j];

	int idx1=0,idx2=0,idx3=n-1,idx4=n-1;

	print_spiral(a,idx1,idx2,idx3,idx4);

	return 0;
}
