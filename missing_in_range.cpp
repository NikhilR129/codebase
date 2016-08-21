//incomplete, very lazy to complete it,
//can be done easily
//we have been given an array of ints and a range
//we have to tell the ints which are no in the array but in the range
//use either sorting or hashing
//incomplete sorting part
#include<iostream>
#include<algorithm>
using namespace std;
int myfind(int a[],int low,int high,int x)
{
	
	int mid=(low+high)/2;
	if(a[mid]==x)
		return mid;
	if(a[mid]<x && x<a[mid+1])
		return mid;
	if(x<a[mid])
		return myfind(a,low,mid,x);
	if(x>a[mid])
		return myfind(a,mid+1,high,x);
}
/*inline void fun1(int a[],int &n,int &l,int &r)
{
	sort(a,a+n);
	int low=myfind(a,n,l);
	int high=myfind(a,n,r);

	
	for(i=l;i<=high;i++)
	{
		int diff=a[i]-a[i-1];
	}
}*/
int main()
{
	int n,i,j,l,r;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];

	while(true)
	{
		cin>>l;
		cout<<myfind(a,0,n-1,l)<<endl;
	}
	return 0;
	}
	
		

