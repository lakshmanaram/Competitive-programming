#include <bits/stdc++.h>
using namespace std;
int main(){
	long n;
	cin>>n;
	long long ans = 0;
	string arr;
	cin>>arr;
	for(long i=0;i<n;i++){
		char x;
		cin>>x;
		ans += min(abs(x-arr[i]),10 - abs(x-arr[i]));
	}
	cout<<ans;
	return 0;
}