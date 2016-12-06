#include <bits/stdc++.h>
using namespace std;
int mod10(long long a) {
	if(a == 0)
		return 1;
	if(a == 1)
		return 8;
	int temp = mod10(a/2);
	if(a%2 == 0)
		return (temp*temp) %10;
	else
		return (temp*temp*8) %10;
}
int main() {
	long long n;
	cin>>n;
	cout<<mod10(n);
	return 0;
}