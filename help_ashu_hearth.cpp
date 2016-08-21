#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#define ll long long int
using namespace std;

int make_st_util(ll a[],ll st[],ll start,ll end,ll idx)
{
	if(start==end)
	{
		st[idx]=(a[start]%2==0);
		return st[idx];
	}

	ll mid=(start+end)/2;

	ll left=make_st_util(a,st,start,mid,2*idx+1);
	ll right=make_st_util(a,st,mid+1,end,2*idx+2);
	return st[idx]=left+right;
}
ll *make_st(ll a[],ll n)
{
	ll maxsize=pow(2,ceil(log2(n))+1)-1;
	ll *st=(ll *)malloc(sizeof(ll)*maxsize);
	make_st_util(a,st,0,n-1,0);

	return st;
}
void update(ll a[],ll st[],ll start,ll end,ll index,ll key,ll idx)
{
	if(start==end)
	{
		a[start]=key;
		st[idx]=((key%2)==0);
		return;
	}
	ll mid=(start+end)/2;
	if(index>=start && index<=mid)
		update(a,st,start,mid,index,key,2*idx+1);

	else update(a,st,mid+1,end,index,key,2*idx+2);

	st[idx]=st[2*idx+1]+st[2*idx+2];
}

ll even_in_range(ll st[],ll start,ll end,ll l,ll r,ll idx)
{
	if( end<l || start>r )
		return 0;
	if(start>=l && end<=r)
		return st[idx];

	ll mid=(start+end)/2;

	return even_in_range(st,start,mid,l,r,2*idx+1)+even_in_range(st,mid+1,end,l,r,2*idx+2);
}




int main()
{
	ll n,i,q,x,y,type;
	scanf("%lld",&n);
	ll a[n];
	ll maxsize=pow(2,ceil(log2(n))+1)-1;
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);

	ll *st=make_st(a,n);

	/*for(i=0;i<maxsize;i++)
		cout<<st[i]<<" ";
		*/
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld%lld%lld",&type,&x,&y);
		if(type==0)
			update(a,st,0,n-1,x-1,y,0);
		else if(type==1)
			cout<<even_in_range(st,0,n-1,x-1,y-1,0)<<endl;
		else cout<<y-x+1-even_in_range(st,0,n-1,x-1,y-1,0)<<endl;
	}

	return 0;
}


