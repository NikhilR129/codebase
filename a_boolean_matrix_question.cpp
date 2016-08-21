#include<iostream>
using namespace std;
int main()
{
	int m,n,i,j;
	cin>>m>>n;
	bool a[m][n];
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			cin>>a[i][j];

	bool flag1=false,flag2=false;
	for(i=0;i<n;i++)
		if(a[0][i]) flag1=true;

	for(i=0;i<m;i++)
		if(a[i][0]) flag2=true;

	for(i=1;i<m;i++)
	{
		for(j=1;j<n;j++)
			if(a[i][j])
				a[0][j]=true,a[i][0]=true;
	}

	for(i=1;i<m;i++)
		for(j=1;j<n;j++)
		{
			if(a[0][j]) a[i][j]=true;
			if(a[i][0]) a[i][j]=true;
		}
	if(flag1)
	for(i=0;i<n;i++)
		a[0][i]=true;

	if(flag2)
	for(i=0;i<m;i++)
		a[i][0]=true;


	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
			cout<<endl;
	}
	return 0;
}

