#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	set<string> stset;
	for(int i=0;i<s.size();i++) {
		string n = s.substr(i)+s.substr(0,i);
		stset.insert(n);
	}
	cout<<stset.size();
	return 0;
}