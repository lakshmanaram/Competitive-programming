#include <bits/stdc++.h>
using namespace std;
int main(){
	long n;
	cin>>n;
	set<long long> arr;
	for(long i=0;i<n;i++){
		long long x;
		cin>>x;
		arr.insert(x);
	}
	if(arr.size()>3)
		cout<<"NO"<<endl;
	else if(arr.size() < 3)
		cout<<"YES"<<endl;
	else {
		set<long long>::iterator sit = arr.begin();
		vector<long long> ans;
		while(sit!= arr.end()){
			ans.push_back(*sit);
			sit++;
		}
		if(ans[1]-ans[0] == ans[2] - ans[1])
			cout<<"YES"<<endl;
		else 
			cout<<"NO"<<endl;
	}
	return 0;
}