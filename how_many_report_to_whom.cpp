#include<iostream>
#include<vector>
using namespace std;

int fun(vector< vector<int> > &v,int emp,int ans[])
{
	if(v[emp].empty())
		return 0;
	if(ans[emp]>0)
		return ans[emp];
	for(int i=0;i<v[emp].size();i++)
	{
		(ans[emp]+=1+fun(v,v[emp][i],ans));
	}
	return ans[emp];
}	
				

int main()
{
	int x,y;
	int n,i;
	cin>>n;
	vector< vector<int> > v(n);
	int ans[n];
	for(i=0;i<n;i++)
		ans[i]=0;
	while(true)
	{
		cin>>x>>y;
		if(x==y)
			break;
		v[y].push_back(x);
	}
	for(i=0;i<n;i++)
		cout<<i<<" "<<fun(v,i,ans)<<endl;

	return 0;
}
