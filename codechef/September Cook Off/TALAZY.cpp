#include <bits/stdc++.h>
using namespace std;
long long find_ans(long long n, long long b, long long m) {
	if(n == 1)
		return m;
	long long problems = (n+1)/2;
	return m*problems + b + find_ans(n-problems,b,2*m);
}
int main(){

	int t;
	cin>>t;
	while(t--){
		long long n,b,m;
		cin>>n>>b>>m;
		long long ans = find_ans(n,b,m);
		cout<<ans<<endl;
	}
}