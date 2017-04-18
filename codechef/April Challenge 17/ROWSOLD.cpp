#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		long long ans= 0;
		long long no = 0;
		string x;
		cin>>x;
		long long streak = 0;
		for(long i=0;i<x.size();i++) {
			if(x[i] == '1') {
				if(streak != 0){
					ans += no;
					ans += no*streak;
				}
				no++;
				streak = 0;
			} else 
				streak++;
		}
		if(streak != 0){
			ans += no;
			ans += no*streak;
		}
		cout<<ans<<endl;
	}
	return 0;
}