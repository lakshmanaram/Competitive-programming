#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--) {
		double a,b;
		cin>>a>>b;
		a = a*2/(b*3);
		cout<<fixed<<setprecision(7)<<a<<endl;
	}
	return 0;
}
