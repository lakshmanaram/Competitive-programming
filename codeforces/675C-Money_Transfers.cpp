#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n;
	cin>>n;
	long long ans = 0;
	vector<long long> a(n);
	for(long i=0;i<n;i++)
		cin>>a[i];
	for(long i=0;i<n-1;i++){
		if(a[i]!=0)
			ans++;
		a[i] = 0;
		a[i+1] += a[i];
	}
	long long ans1 = 0;
	for(long i=n-1;i>0;i--){
		if(a[i]!=0)
			ans1++;
		a[i] = 0;
		a[i-1] += a[i];
	}
	cout<<min(ans,ans1);
	return 0;
}
