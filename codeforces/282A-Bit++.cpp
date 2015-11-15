#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n=0,ans=0;
	cin>>n;
	while(n--)
	{
		char ch[3];
		cin>>ch;
		if(ch[1]=='+'||ch[0]=='+')
			ans++;
		else
			ans--;
	}
	cout<<ans;
	return 0;
}
