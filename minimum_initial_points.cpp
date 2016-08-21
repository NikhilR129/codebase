#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
	int m,i,j,n;
	cin>>m>>n;

	int a[m][n];

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			cin>>a[i][j];
	}

	int dp[m][n];

	dp[m-1][n-1]=(a[m-1][n-1]>0?1:abs(a[m-1][n-1])+1);
	
	for(j=n-2;j>=0;j--)
		dp[m-1][j]=max(dp[m-1][j+1]-a[m-1][j],1);

	for(i=m-2;i>=0;i--)
		dp[i][n-1]=max(dp[i+1][n-1]-a[i][n-1],1);

	for(i=m-2;i>=0;i--)
	{
		for(j=n-2;j>=0;j--)
		{
			int min_on_exit=min(dp[i+1][j],dp[i][j+1]);
			dp[i][j]=max(min_on_exit-a[i][j],1);
		}
	}

	cout<<dp[0][0]<<endl;


	return 0;
}


