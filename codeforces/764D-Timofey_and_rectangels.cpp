#include <bits/stdc++.h>
using namespace std;
int main() {
	long n;
	cin>>n;
	cout<<"YES"<<endl;
	while(n--) {
		long long a,b,c,d;
		cin>>a>>b>>c>>d;
		a = a%2;
		b = b%2;
		if(a&&b)
			cout<<1;
		else if(a&&!b)
			cout<<2;
		else if(!a&&b)
			cout<<3;
		else
			cout<<4;
		cout<<endl;
	}
	return 0;
}