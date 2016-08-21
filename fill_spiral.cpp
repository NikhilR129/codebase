#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int count;
void fill_spiral(int **a,int n,int idx1,int idx2,int idx3,int idx4)
{
	int i;
	if(idx1>=0 && idx2>=0 && idx3<=n-1 && idx4<=n-1)
	{
		//cout<<idx1<<idx2<<" "<<idx3<<idx4<<endl;
		for(i=idx1+1;i<=idx3;i++)
			a[i][idx2]=count++;
		for(i=idx2+1;i<=idx4;i++)
			a[idx3][i]=count++;
		for(i=idx3-1;i>=idx1;i--)
			a[i][idx4]=count++;
		for(i=idx4-1;i>=idx2;i--)
			a[idx1][i]=count++;

		fill_spiral(a,n,idx1-1,idx2-1,idx3+1,idx4+1);
	}
}
void print_matrix(int **a,int n)
{
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			cout<<a[i][j]<<"   ";
	cout<<endl<<endl;
	}

}


int main()
{
	int n,i,j;
	cin>>n;
	int **a=(int**)malloc(sizeof(int *)*n);

	for(i=0;i<n;i++)
		a[i]=(int *)malloc(sizeof(int)*n);
	
	int idx1,idx2,idx3,idx4;
	if(n%2)
	{
		idx1=n/2-1,idx2=n/2-1,idx3=n/2+1,idx4=n/2+1;
		a[n/2][n/2]=1;
		count=2;
	}
	else
	{
		idx1=n/2-1,idx2=n/2-1,idx3=idx1+1,idx4=idx2+1;
		count=1;
	}

	fill_spiral(a,n,idx1,idx2,idx3,idx4);

	print_matrix(a,n);

	return 0;
}

