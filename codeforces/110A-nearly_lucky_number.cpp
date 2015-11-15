#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int i=0,ans=0;
	for(;i<s.length();i++)
	{
		if(s[i]=='4'||s[i]=='7')
			ans++;
	}
	if(ans==4||ans==7)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}