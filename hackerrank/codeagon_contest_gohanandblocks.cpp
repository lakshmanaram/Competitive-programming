#include<bits/stdc++.h>
using namespace std;
set<string> s;
void func(string n, stack<char> c, string old)
{
	if(!c.empty())
	{
		string n1 = n;
		n1.append(1,c.top());
		stack<char> c1 = c;
		c1.pop();
		func(n1,c1,old);
	}
	if(old.length()!=0)
	{
		c.push(old[0]);
		old.erase(old.begin());
		func(n,c,old);
	}
	if(c.empty()&&old.length()==0)
	{
		s.insert(n);
	}
	return;
}
int main()
{
	string a;
	cin>>a;
	stack<char> c;
	string n;
	func(n,c,a);
	set<string>::iterator it;
	int i=1;
	for (it=s.begin(); it!=s.end(); ++i,++it)
    	cout<<i<<" "<<*it<<endl;
  return 0;
}
