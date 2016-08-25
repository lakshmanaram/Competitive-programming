#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,b,d;
	cin>>n>>b>>d;
	long long ans = 0;
	long long waste = 0;
	for(long long i=0;i<n;i++) {
		long long x;
		cin>>x;
		if(x > b)
			continue;
		waste += x;
		if(waste > d){
			waste = 0;
			ans++;
		}
	}
	cout<<ans<<endl;	
	return 0;
}