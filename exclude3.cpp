#include<cstdio>
#include<iostream>
#include<vector>
#define max 1000000000
#define ll long long int
using namespace std;
int main()
{
	int n,i;
	char a[1001];
	scanf("%d\n",&n);
	while(n--)
	{
		i=0;
		gets(a);
		long long int count=0;
		while(a[i]!='\0')
		{
			if(a[i]=='$')
			{
				int j=i+1;
				while(!((a[j]>='a' && a[j] <='z') || a[j]>='A' && a[j]<='Z' || a[j]=='\0'))
				{
					if(a[j]>='0'&& a[j]<='9')
						count=count*10+(a[j]-'0');
					j++;
				}
				i=j-1;
			}
			i++;
		}
		cout<<"$"<<count<<endl;
	}
	
}

	
