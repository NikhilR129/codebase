#include<iostream>
#include<queue>
#include<cstdlib>
#include<climits>

using namespace std;

struct node
{
	int x;
	int y;
	int level;
};
void shortest_path(int **a,int **visited,int idx1,int idx2,int idx3,int idx4,int n,int *ans)
{
	node n1;
	queue<node> q;
	n1.x=idx1,n1.y=idx2,n1.level=1;
	q.push(n1);
	while(!q.empty())
	{
		n1=q.front();
		q.pop();
		if(n1.x == idx3 && n1.y==idx4 && n1.level<*ans)
			*ans=n1.level;

		if(!visited[n1.x][n1.y])
		{
			visited[n1.x][n1.y]=true;

			if(n1.x+1 <=n-1 && a[n1.x+1][n1.y]==1 && !visited[n1.x+1][n1.y])
			{
				node N;
				N.x=n1.x+1;
				N.y=n1.y;
				N.level=n1.level+1;
				//cout<<N.x<<" "<<N.y<<" "<<N.level<<endl;
				q.push(N);
			}
			if(n1.x-1 >=0 && a[n1.x-1][n1.y]==1 && !visited[n1.x-1][n1.y])
			{
				node N;
				N.x=n1.x-1;
				N.y=n1.y;
				N.level=n1.level+1;
				q.push(N);


			}               
			if(n1.y+1 <=n-1 && a[n1.x][n1.y+1]==1 && !visited[n1.x][n1.y+1])
			{
				node N;
				N.x=n1.x;
				N.y=n1.y+1;
				N.level=n1.level+1;
				q.push(N);
			}
			if(n1.y-1 >=0 && a[n1.x][n1.y-1]==1 && !visited[n1.x][n1.y-1])
			{
				node N;
				N.x=n1.x;
				N.y=n1.y-1;
				N.level=n1.level+1;
				q.push(N);
			}

		}
	}
}

int main()
{
	int n,i,j,idx1,idx2,idx3,idx4,ans=INT_MAX;
	cin>>n;
	int **a=(int **)malloc(sizeof(int *)*n);
	int **visited=(int **)malloc(sizeof(int *)*n);

	for(i=0;i<n;i++)
	{
		a[i]=(int *)malloc(sizeof(int)*n);
		visited[i]=(int *)malloc(sizeof(int)*n);
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
			visited[i][j]=false;
		}
	}

	cin>>idx1>>idx2;
	cin>>idx3>>idx4;

	if(a[idx1][idx2]==1 && a[idx3][idx4]==1)
	{
		shortest_path(a,visited,idx1,idx2,idx3,idx4,n,&ans);
		cout<<ans;
	}
	else
		cout<<"No route"<<endl;

	return 0;
}


