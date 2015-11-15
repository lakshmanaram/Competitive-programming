#include<iostream>
using namespace std;
int main()
{
	int hash[1000002];
	fill(hash,hash+1000001,0);
	int t;
	long val=0;
	int maxav=0,tempav=0;
	cin>>t;
	char ch;
	while(t--)
	{
		cin>>ch;
		cin>>val;
		if(ch=='+')
		{
			tempav++;
			hash[val]=1;
		}
		else
		{	
			if(hash[val]==1)
			{
				hash[val]=0;
				if(tempav>maxav)
					maxav = tempav;
				tempav--;
			}
			else
			{
				if(maxav!=0)
					maxav++;
				else
					maxav+=tempav+1;
			}
		}
	}
	if(tempav>maxav)
		maxav = tempav;
	cout<<maxav;
	return 0;
}