#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

int getmin(int st[],int start,int end,int low,int high,int idx)
{
	if(end<low || start>high)
		return INT_MAX;
	
	if(start==end)
		return st[idx];

	int mid=(start+end)/2;

	return min(getmin(st,start,mid,low,high,2*idx+1),getmin(st,mid+1,end,low,high,2*idx+2));
}

void update(int st[],int start,int end,int index,int key,int idx)
{
	if(start==end && start==index)
	{
		st[idx]=key;
		return;
	}

	int mid=(start+end)/2;

	if(index<=mid)
		update(st,start,mid,index,key,2*idx+1);
	else if(index>mid)
		update(st,mid+1,end,index,key,2*idx+2);
	
	st[idx]=min(st[idx],key);
}


void createstutil(int st[],int a[],int start,int end,int idx)
{
	if(start==end)
	{
		st[idx]=a[start];
		return;
	}

	int mid=(start+end)/2;

	createstutil(st,a,start,mid,2*idx+1);
	createstutil(st,a,mid+1,end,2*idx+2);

	st[idx]=min(st[2*idx+1],st[2*idx+2]);

}

int* createst(int a[],int n)
{
	int size=pow(2,(int)(ceil(log2(n)))+1)-1;
	int *st=(int*)malloc(sizeof(int)*size);
	createstutil(st,a,0,n-1,0);
	return st;
}

int main()
{
	int n,i;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];

	int *st=createst(a,n);
	int size=pow(2,(int)(ceil(log2(n)))+1)-1;
	/*for(i=0;i<pow(2,(int)(ceil(log2(n)))+1)-1;i++)
		cout<<st[i]<<" "<<endl;
	*/
	int ch,low,high,idx,key;

	while(1)
	{
		cin>>ch;
		if(ch==1)
		{
			cin>>low>>high;
			cout<<getmin(st,0,n-1,low,high,0)<<endl;
	
		}
		if(ch==2)
		{
			cin>>idx>>key;
			update(st,0,n-1,idx,key,0);
		}
	}

	return 0;
}
