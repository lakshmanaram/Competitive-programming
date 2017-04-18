#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		set<string> a;
		for(int i=0;i<4;i++) {
			string x;
			cin>>x;
			a.insert(x);
		}
		int ans = 0;
		for(int i=0;i<4;i++) {
			string x;
			cin>>x;
			if(a.find(x)!=a.end())
				ans++;
		}
		if(ans >= 2)
			cout<<"similar"<<endl;
		else
			cout<<"dissimilar"<<endl;
	}
	return 0;
}