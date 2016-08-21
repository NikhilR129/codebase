#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int i,n,k;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];

	int minleft[n],minright[n];

	cin>>k;

	int counter=0;

	i=0;

	while(i<n)
	{
		if(counter==k)
			counter=0;

		if(counter==0)
		minleft[i]=a[i];

		else
			minleft[i]=min(minleft[i-1],a[i]);

		i++;
		counter++;
	}

	i=n-1;
	counter=0;

	while(i>=0)
	{
		if(counter==k)
			counter=0;

		if(counter==0)
			minright[i]=a[i];

		else
			minright[i]=min(minright[i+1],a[i]);

		i--;
		counter++;
	}
	
	for(i=0;i<n;i++)
	{
		if(i+k-1 < n)
			cout<<min(minright[i],minleft[i+k-1])<<" ";

		else
			cout<<minright[i]<<" ";
	}

return 0;

}



