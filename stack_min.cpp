#include<iostream>
#include<stack>
using namespace std;
int min_now;

void stack_push(stack<int> &s,int x)
{
	if(s.empty())
		s.push(x),min_now=x;
	else if(x<min_now)
		s.push(2*x-min_now),min_now=x;
	else
		s.push(x);
}
void pop(stack<int> &s)
{
	if(s.empty())
	{
		min_now=-10000;
		return;
	}
	else
	{
		int tmp=s.top();
		s.pop();
		if(tmp<min_now)
			min_now=2*min_now-tmp;
	}
}

int main()
{
//std:cout.sync_with_stdio(false);

    stack<int> s;
	int ch,i,y;
	while(true)
	{
		cin>>ch;
		if(ch==1)
		{
			cin>>y;
			stack_push(s,y);
		}
		if(ch==2)
		{
			pop(s);
			//cout<<min_now<<endl;
		}
		if(ch==3)
		{
			if(s.empty())
				cout<<"stack empty"<<endl;
			else
				cout<<min_now<<endl;
		}
	}
	return 0;
}
	

