#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n;
	map<int,int> cit;
	cin>>m>>n;
	int i,j;
	for(i=0;i<n;i++)
	{
		int pos=0;
		int val,temp;
		cin>>val;
		for(j=1;j<m;j++)
		{
			cin>>temp;
			if(temp>val)
			{
				val=temp;
				pos = j;
			}
		}
		cit[pos]++;
	}	
	int val=0,pos=101;
	map<int,int>::iterator it = cit.begin();
	while(it!=cit.end())
	{
		if(it->second>val)
		{
			val = it->second;
			pos = it->first;
		}
		else if(it->second==val)
		{
			if(pos>it->first)
			{
				pos= it->first;
			}
		}
		it++;
	}
	cout<<pos+1;
	return 0;
}
