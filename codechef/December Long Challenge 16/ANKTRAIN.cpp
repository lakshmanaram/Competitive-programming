#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		if(n%8 == 7)
			n = n+1;
		else if(n%8 == 0)
			n = n-1;
		else if(n%8 < 4) {
			n = n+3;
		} else
			n = n-3;
		cout<<n;
		switch(n%8){
			case 1:
			cout<<"LB";
			break;
			case 2:
			cout<<"MB";
			break;
			case 3:
			cout<<"UB";
			break;
			case 4:
			cout<<"LB";
			break;
			case 5:
			cout<<"MB";
			break;
			case 6:
			cout<<"UB";
			break;
			case 7:
			cout<<"SL";
			break;
			default:
			cout<<"SU";

		}
		cout<<endl;
	}
	return 0;
}