#include <bits/stdc++.h>
using namespace std;
int main() {
	int k,r;
	cin>>k>>r;
	k = k%10;
	label:
	int i;
	for(i=1;i<=10;i++) {
		if((i*k)%10 == r){
			cout<<i;
			break;
		}
	}	
	if(i == 11){
		r = 0;
		goto label;
	}
	return 0;
}