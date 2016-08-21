#include<iostream>
using namespace std;
float find_prob(int steps,int n,int x,int y)
{
	if(x>=n || x<0 || y<0 || y>=n)
		return 0.0;
	else if(steps==0)
		return 1.0;

	return 0.25*find_prob(steps-1,n,x+1,y)+0.25*find_prob(steps-1,n,x,y+1)+0.25*find_prob(steps-1,n,x-1,y)+0.25*find_prob(steps-1,n,x,y-1);
}
int main()
{
	int n,i,x,y,s;
	cin>>n;
	cin>>x>>y;
	cin>>s;
	cout<<find_prob(s,n,x,y)<<endl;

	return 0;
}
