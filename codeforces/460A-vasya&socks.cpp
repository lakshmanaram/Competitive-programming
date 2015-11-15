#include<iostream>
using namespace std;
int main()
{
	int n,m,ans=0,rem;
	cin>>n>>m;
	while(n!=0)
	{
		ans += ((int)(n/m) * m);
		n = (n%m)+n/m;
		if(n<m)
			break;
	}
	ans+=n;
	cout<<ans;

	return 0;
}