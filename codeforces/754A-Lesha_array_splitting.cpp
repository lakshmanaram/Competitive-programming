#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	bool flag = false;
	vector<int> arr(n);
	for(int i=0;i<n;i++) {
		cin>>arr[i];
		if(arr[i]!=0)
			flag = true;
	}
	if(flag){
		cout<<"YES"<<endl;
		vector<pair<int,int> > ans;

		int l = 1, r = 1;

		for(int i=0;i<n;i++){
			if(arr[i] != 0){
				ans.push_back(make_pair(l,r));
				r++;
				l = r;
			} else {
				if(ans.size() == 0)
					r++;
				else{
					ans[ans.size()-1].second++;
					r++;
					l = r;
				}
			}
		}
		if(ans[ans.size()-1].second != n)
			ans.push_back(make_pair(l,n));

		cout<<ans.size()<<endl;
		for(int i=0;i<ans.size();i++){
			cout<<ans[i].first<<" "<<ans[i].second<<endl;
		}
	} else {
		cout<<"NO"<<endl;
	}

	return 0;
}