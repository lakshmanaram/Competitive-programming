#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b,c,d,n;
	cin>>n>>a>>b>>c>>d;
	vector<long long> comp;
	comp.push_back(0);
	comp.push_back(d-a);
	comp.push_back(c-b);
	comp.push_back(c+d-a-b);
	vector<long long>::iterator maxit = max_element(comp.begin(),comp.end());
	vector<long long>::iterator minit = min_element(comp.begin(),comp.end());
	long long l = n + *minit, r = 1+*maxit;
	long long ans = n;
	if(l>=r)
		ans *= (l-r+1);
	else
		ans = 0;
	cout<<ans;
	return 0;
}
