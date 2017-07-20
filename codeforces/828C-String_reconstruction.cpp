#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
int main(){
	long n;
	cin>>n;
	vector<string> arr(n);
	vector<pair<long, pair<long,long> > > a;
	long end = 0;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		arr[i] = s;
		long k;
		cin>>k;
		while(k--){
			long j;
			cin>>j;
			a.pb(mp(j,mp(1000001-s.size(),i)));
			end = max(end, (long)(j-1+s.size()));
		}
	}
	string x(end,'a');
	sort(a.begin(),a.end());
	long index = 1;
	for(long i=0;i<a.size();i++){
		a[i].second.first = 1000001 - a[i].second.first;
		if(index >= a[i].first+a[i].second.first) {
			continue;
		}
		else {
			long j = max(index-1, a[i].first-1);
			long k = max((long)0,index-a[i].first);
			// cout<<x<<" "<<a[i].second.first<<" "<<k<<" "<<arr[a[i].second.second].substr(k)<<endl;
			x.replace(j,a[i].second.first-k,arr[a[i].second.second].substr(k));
			// cout<<x<<endl;
			// string s = arr[a[i].second.second];
			// for(;k<s.size();k++,j++){
			// 	x[j] = s[k];
			// }
			index = a[i].first+a[i].second.first;
		}
	}
	cout<<x;
	return 0;
}