#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n,ans=1;
	cin>>n;
	string a,temp;
	cin>>a;
	temp=a;
	n--;
	while(n--)
	{
		cin>>a;
		if(temp!=a)
		{
			temp=a;
			ans++;
		}
	}	
	cout<<ans;
	return 0;
}