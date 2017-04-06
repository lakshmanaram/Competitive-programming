#include <bits/stdc++.h>
using namespace std;

int main() {
	double n, k;
	double s , pockets;
	cin>>n>>k;
	while(n--) {
		cin>>s;
		pockets += ceil(s/k);
	}
	cout<<(long long)ceil(pockets/2.0);
	return 0;

}
