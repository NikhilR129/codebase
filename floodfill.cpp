#include<bits/stdc++.h>
using namespace std;

void floodfill(int **a,int n,int x,int y,int color,int orig_color)
{
	if(color==orig_color)
		return;
	if(x >=n || x<0 || y>=n || y<0)
		return;
	if(a[x][y]!=orig_color)
		return;
	a[x][y]=color;
	floodfill(a,n,x+1,y,color,orig_color);
	floodfill(a,n,x,y+1,color,orig_color);
	floodfill(a,n,x-1,y,color,orig_color);
	floodfill(a,n,x,y-1,color,orig_color);

}
void display(int **a,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
	int n,i,x,y,color,j,tmp,flag;
	cin>>n;
	int **a=(int **)malloc(sizeof(int *)*n);
	for(i=0;i<n;i++)
		a[i]=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>a[i][j];
	while(true)
	{
		cin>>x>>y>>color;
		floodfill(a,n,x,y,color,a[x][y]);
		display(a,n);
	}
	return 0;
}


