#include <bits/stdc++.h>
using namespace std;
int getCount(string a, string b) {
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int ans = 0;
	int i = 0, j = 0;
	while(i < a.size()){
		if(a[i] <= b[j]){
			ans += b[j]-a[i];
			j++;
		} else {
			if(j < a.size()) {
				b += b[j];
				j++;
				i--;
			} else {
				ans += 26 - a[i] + b[j];
				j++;
			}
		}
		i++;
	}
	return ans;
}
int main(){

	while(true){
	string a, b;
	cin>>a>>b;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int count  = 2000;
	for(int i=0;i<a.size();i++) {
		int lcount = 0;
		for(int j=i,k=0;k < a.size(); j= (j+1)%a.size(),k++) {
			if(b[k] >= a[j]) {
				lcount += (b[k]-a[j]);
			} else {
				lcount += 26 - a[j] + b[k];
			}
		}
		count = min(count, lcount);
	}
	cout<<count<<endl;
	cout<<getCount(a,b)<<endl;
	}
	return 0;
}