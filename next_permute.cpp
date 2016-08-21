#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	string s;
	cin>>s;
	next_permutation(s.begin(),s.end());
	cout<<s<<endl;
}
