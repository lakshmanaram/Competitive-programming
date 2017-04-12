#include <bits/stdc++.h>
using namespace std;
class BuildingStrings {
public: 
	vector <string> findAny(int k) {
		vector<string> ans;
		if(k <= 50) {
			string a(k,'a');
			ans.push_back(a);
			return ans;
		} else {
			int x = 26;
			while(50 * x <= k) {
				string a(50,'a');
				for(int i=0;i<x;i++) {
					a[i] += i;
				}
				ans.push_back(a);
				k -= 50*x;
			}
			while(50 * x > k ) {
				x--;
			}
			if(x != 0) {
				string a(50,'a');
				for(int i=0;i<x;i++) {
					a[i] += i;
				}
				ans.push_back(a);
				k -= 50*x;
			}
			if(k!=0 ){
				string a(k,'a');
				ans.push_back(a);
			}
		}
		return ans;
	}
};
int main() {
	BuildingStrings bs;
	int y;
	cin>>y;
	vector<string> x = bs.findAny(y);
	for(int i=0;i<x.size();i++) {
		cout<<x[i]<<endl;
	}
	return 0;
}