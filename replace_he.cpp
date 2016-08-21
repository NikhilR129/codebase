#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string fun(string &s1,string &s2,string::iterator it1,string::iterator it2)
{
	if(it1==s1.end() || it2==s2.end())
		return s1;
	if(*it1>*it2)
	{
		*it1=*it2;
		return fun(s1,s2,it1+1,it2+1);
	}
	return fun(s1,s2,it1+1,it2);
}

int main()
{
	string s1,s2;
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>s1>>s2;
		//cout<<s1<<endl<<s2;
		sort(s2.begin(),s2.end());
		string s=fun(s1,s2,s1.begin(),s2.begin());
		cout<<s<<endl;
	}
	return 0;
}
