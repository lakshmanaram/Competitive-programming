#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
		string a;
		cin>>a;
		long i;
		for(i=0;i<a.size();i++) {
			if(a[i] == '0') {
				if ((i>=1 && a[i-1] == '*')||(i>=2 && a[i-2] == '*'))
					continue;
				else{
					cout<<"NO"<<endl;
					break;
				}
			}
		}
		if(i == a.size())
			cout<<"YES"<<endl;
	}
	return 0;
}