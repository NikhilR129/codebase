#include<iostream>
using namespace std;
int maxdiff2(int a[],int n)
{
	int i,max_ending_here=0,max_so_far=0;
	for(i=0;i<n-1;i++)
	{
		max_ending_here=max_ending_here+a[i+1]-a[i];
		if(max_ending_here<0)
			max_ending_here=0;

		if(max_ending_here>max_so_far)
			max_so_far=max_ending_here;
	}

	return max_so_far;
}
int maxdiff1(int a[],int n)
{
	int i,maxdiff=0,tmp;
	int maxelm=a[n-1];

	for(int i=n-2;i>=0;i--)
	{
		if(a[i]>maxelm)
			maxelm=a[i];
		else
		{
			tmp=maxelm-a[i];
			if(tmp>maxdiff)
				maxdiff=tmp;
		}
	}
	return maxdiff;
}

int maxdiff3(int a[],int n)
{
	int i,minelm=a[0],maxdiff=0,tmp;
	for(i=1;i<n;i++)
	{
		if(a[i]<minelm)
			minelm=a[i];
		else
		{
			tmp=a[i]-minelm;
			if(tmp>maxdiff)
				maxdiff=tmp;
		}
	}
	return maxdiff;
}


int main()
{
	int n,i,j;
	cin>>n;
	int a[n],b[n],c[n];
	for(i=0;i<n;i++)
		cin>>a[i];

	cout<<maxdiff1(a,n);
	cout<<endl;
	cout<<maxdiff2(a,n);
	cout<<endl;
	cout<<maxdiff3(a,n);
}




