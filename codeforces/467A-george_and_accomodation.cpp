#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	int ans=0;
	int p,q;
	cin>>n;
	while(n--)
	{
		cin>>p>>q;
		if(q-p>=2)
			ans++;
	}
	cout<<ans;
	return 0;
}