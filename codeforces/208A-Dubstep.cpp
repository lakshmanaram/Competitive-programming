#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i;
	stack<char> mys;
	string a;
	cin>>a;
	int flag=0;
	for(i=a.length()-1;i>=0;i--)
	{
		mys.push(a[i]);
		if(flag==0)
		{
			if(mys.top()=='B')
				flag=1;
		}
		else if(flag==1)
		{
			if (mys.top()=='U') {
				flag=2;
			}
			else
			{
				if(mys.top()=='B')
					flag=1;
				else
					flag=0;
			}
		}
		else
		{
			if(mys.top()=='W'){
				mys.pop();
				mys.pop();
				mys.pop();
				if(!mys.empty())
				if(mys.top()!=' ')
					mys.push(' ');
				flag=0;
			}
			else if(mys.top()=='B')
				flag=1;
			else
				flag=0;
		}
	}
	while(mys.top()==' ')
		mys.pop();
	while(!mys.empty())
	{
		cout<<mys.top();
		mys.pop();
	}
	return 0;
}
