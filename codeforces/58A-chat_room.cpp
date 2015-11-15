#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s,ts="hello";
	cin>>s;
	int i=0,j=0;
	for(;i<s.length();i++)
	{
		if(ts[j]==s[i])
		{
			j++;
			if(j==5)
			{
				cout<<"YES";
				return 0;
			}
		}

	}	
	cout<<"NO";
	return 0;
}