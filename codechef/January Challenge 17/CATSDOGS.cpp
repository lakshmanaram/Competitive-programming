#include <bits/stdc++.h>
using namespace std;
int main() {
	long t;
	cin>>t;
	string yes = "yes";
	string no = "no";
	while(t--) {
		long long c,d,l;
		cin>>c>>d>>l;
		if(l%4!=0 || d*4 > l){
			cout<<no<<endl;
		} else {
			l -= d*4;
			c -= l/4;
			if(c < 0 || c > 2*d)
				cout<<no<<endl;
			else
				cout<<yes<<endl;
		}
	}
	return 0;
}
