#include <bits/stdc++.h>
using namespace std;
int main(){

	long long t;
	cin>>t;
	t--;
	long long n = t/3;
	n++;
	n = log2(n);
	// cout<<n;
	long long a = pow(2,n);
	t = t - 3*(a-1);
	n = 3*a;
	cout<<n-t;
	return 0;
}