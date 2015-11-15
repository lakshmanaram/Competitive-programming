#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m;
	cin>>n>>m;
	if(n!=1)
	{
		if(m>n/2)
			cout<<m-1;
		else
			cout<<m+1;
	}
	else
		cout<<1;
	return 0;
}
