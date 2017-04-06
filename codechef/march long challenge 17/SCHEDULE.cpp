#include <bits/stdc++.h>
#define sf second.first
#define ss second.second
#define pb push_back
using namespace std;
int main() {
	long t;
	cin>>t;
	while(t--) {
		long n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		char prev = '2';
		long count = 0;
		vector<pair<long,pair<long,long> > > dp;
		for(long j=0;j<n;j++){
			if(prev != s[j]){
				if(count > 0) {
					dp.pb(make_pair(count,make_pair(count,0)));
				}
				count = 1;
				prev = s[j];
			} else {
				count++;
			}
		}
		dp.pb(make_pair(count,make_pair(count,0)));
		int y = 0;
		long tans = 0;
		for(long j=0;j<n;j++) {
			if(s[j] != '0'+y)
				tans++;
			y = 1-y;
		}
		if(tans <= k){
			cout<<1<<endl;
			continue;
		}
		y = 1;
		tans = 0;
		for(long j=0;j<n;j++) {
			if(s[j] != '0'+y)
				tans++;
			y = 1-y;
		}
		if(tans <= k){
			cout<<1<<endl;
			continue;
		}
		// cout<<"Beginning\n";
		// for(sit=dp.begin();sit!=dp.end();sit++) {
		// 	cout<<sit->first<<" "<<sit->sf<<" "<<sit->ss<<endl;
		// }
		make_heap(dp.begin(),dp.end());
		while(k-- && dp.size()!=0) {
			pair<long,pair<long,long> > x = dp.front();
			if(x.first <= 2)
				break;
			pop_heap(dp.begin(),dp.end());
			dp.pop_back();
			x.ss++;
			x.first = ceil(((double)(x.sf-x.ss))/(x.ss+1));
			dp.pb(x);
			push_heap(dp.begin(),dp.end());
			// cout<<"Iteration\n";
			// for(sit=dp.begin();sit!=dp.end();sit++) {
			// 	cout<<sit->first<<" "<<sit->sf<<" "<<sit->ss<<endl;
			// }
		}
		if(dp.size() != 0 ){
			cout<<dp.front().first<<endl;
		} else {
			cout<<2<<endl;
		}
	}
	return 0;
}