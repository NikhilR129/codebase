#include<iostream>
#include<stack>
#include<string>

using namespace std;

int pr(char ch)
{
	if(ch=='+' || ch=='-')
		return 0;

	if(ch=='*' || ch=='/')
		return 1;
}

void fun(stack<char> &s,char mychar)
{
	if(s.empty())
	{
		s.push(mychar);
		return;
	}

	if(pr(mychar) <= pr(s.top()))
	{
		while(!(s.empty() || pr(s.top())< pr(mychar) || s.top()=='(' ))
		{
			cout<<s.top()<<" ";
			s.pop();
		}
		s.push(mychar);
	}
	else
		s.push(mychar);
}

int main()
{
	stack<char> s;
	string str;
	int i;
	cin>>str;
	for(i=0;i<str.size();i++)
	{
		if(str[i]>='a' && str[i]<='z')
			cout<<str[i]<<" ";
		else if(str[i]=='(')
			s.push(str[i]);
		else if(str[i]==')')
		{
			while(true)
			{
			char c=s.top();
			s.pop();
			if(c=='(')
				break;
			cout<<c<<" ";
			}
		}
		else
		{
			fun(s,str[i]);
		}
	}
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}

	return 0;
}
