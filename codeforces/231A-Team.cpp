#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a,b,c,ans=0;
	while(n--)
	{
		cin>>a>>b>>c;
		if((a==b&&a==1)||(a==c&&a==1)||(c==b&&c==1))
			ans++;
	}
	cout<<ans;
	return 0;
}