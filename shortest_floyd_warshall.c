#include<stdio.h>
int main()
{
	long long int n,i,j,k,x,y;
	scanf("%lld",&n);
	long long int graph[n][n];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			graph[i][j]=0;
	}
	while(1)
	{
		scanf("%lld %lld",&x,&y);
		if(x==-1 && y==-1)
			break;
		graph[x][y]=1;
graph[y][x]=1;
	}
long long int shortest[n][n];

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(graph[i][j]==1)
				shortest[i][j]=graph[i][j];
			else if(i==j)
				shortest[i][j]=0;
			else
				shortest[i][j]=1000000000;
		}
	}

	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				if(shortest[i][k]+shortest[k][j]<shortest[i][j])
					shortest[i][j]=shortest[i][k]+shortest[k][j];
		}
	}

	long long int s;
	scanf("%lld",&s);
	for(i=1;i<=n;i++)
	{
		printf("%lld %lld\n",i,shortest[s][i]);
	}
}
