#include<stdio.h>
int main()
{
	long long int n,i,j,k,x,y;
	scanf("%lld",&n);
	long long int graph[n+1][n+1];
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
	long long int shortest[n+1][n+1],temp[n+1][n+1];

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(graph[i][j]==1 || graph[j][i]==1)
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
				{ shortest[i][j]=shortest[i][k]+shortest[k][j]; temp[i][j]=k; }
		}
	}

	long long int s;
	scanf("%lld",&s);
	for(i=1;i<=n;i++)
	{
		//long long int min=shortest[s][i];
		long long int temp1=100000000;
		if(s==i){
			printf("%lld 0\n",s);
			continue;
		}
		for(j=1;j<=n;j++)
		{
			if(j==i || j==s || j==temp[s][i]) continue;
			if(temp1>shortest[s][j]+shortest[j][i])
			{	temp1=shortest[s][j]+shortest[j][i]; 
 }


		}
		/*if(min==100000000)
		  printf("%lld %lld\n",i,shortest[s][i]);
		  else*/
		printf("\n%lld %lld\n",i,temp1);
}

}
