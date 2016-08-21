#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>

using namespace std;

int main()
{
	string s1,s2;	//declaration of 2 strings i.e. sequences
	cin>>s1>>s2;
	
	int i,j;
	int m=s1.size(),n=s2.size(); //storing the lengths of sequences s1 and s2 in m and n respectively
	int lcs[m+1][n+1]; //To calculate the length of Longest common subsequence using Dynamic Programming(DP)
	
	//Code for DP
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==0 || j==0)  //if either of i or j is 0,length of subsequence will be zero
				lcs[i][j]=0;

			else if(s1[i-1]==s2[j-1]) //if the characters at current indices match,length of lcs will be asfollows
				lcs[i][j]=lcs[i-1][j-1]+1;
			else
				lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]); //else calculated using this
		}
	}
	int lcs_length=lcs[m][n]; //length of lcs
	int idx=lcs_length;
	char lcs_array[idx+1]; //we will store longest common subsequence in this
	lcs_array[idx]='\0'; 
	i=m; j=n;
	//Construction of subsequence using lcs[m][n]
	while(i>0 && j>0)
	{
		if(s1[i-1]==s2[j-1])
		{
			lcs_array[--idx]=s1[i-1];
			i--;
			j--;
		}

		else if(lcs[i-1][j]>lcs[i][j-1])
			i--;
		else
			j--;
	}

	printf("Longest common subsequence is: %s\n",lcs_array);
	printf("And the length is: %d\n",lcs_length);

	return 0;
}


