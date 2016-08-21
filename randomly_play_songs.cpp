#include<iostream>
#include<string>
#include<cstdlib>
#include<algorithm>

using namespace std;

int get_song(int a[],int start,int end)
{
	
	int i=start,j=start;

	for(i=start;i<end;i++)
	{
		if(a[i]>a[end])
		{
			swap(a[i],a[j]);
			j++;
		}
	}
	swap(a[j],a[end]);

	return j;
}

void play_song(int a[],int start,int end)
{
	if(start<=end)
	{
		int pivot=get_song(a,start,end);
		cout<<"Playing song no. : "<<pivot<<endl;
		play_song(a,start,pivot-1);
		play_song(a,pivot+1,end);
	}
}
int main()
{
	int n,i;
	cin>>n;
	
	srand(time(NULL));

	int a[n];

	for(i=0;i<n;i++)
		a[i]=rand()%n;

	play_song(a,0,n-1);

}
	
