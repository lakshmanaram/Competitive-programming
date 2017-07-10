#include <bits/stdc++.h>
using namespace std;
vector<long> get_ans(string s, string t, int x){
	vector<long> ans;
	for(long i=x;i<x+s.size();i++){
		if(s[i-x] != t[i]){
			ans.push_back(i-x+1);
		}
	}
	return ans;
}
int main() {
	long a,b;
	cin>>a>>b;
	string s, t;
	cin>>s>>t;
	vector<long> ans;
	for(int i=0;i<=t.size()-s.size();i++){
		vector<long> temp = get_ans(s,t,i);
		if(i == 0) {
			ans = temp;
		}
		else if (temp.size() < ans.size()) {
			ans = temp;
		}
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	return 0;
}
