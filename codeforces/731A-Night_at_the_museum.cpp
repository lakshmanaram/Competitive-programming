#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	s = "a"+s;
	int ans = 0;
	for(int i=1;i<s.size();i++){
		ans += min(abs(s[i]-s[i-1]), 26-abs(s[i]-s[i-1]));
	}
	cout<<ans<<endl;
	return 0;
}