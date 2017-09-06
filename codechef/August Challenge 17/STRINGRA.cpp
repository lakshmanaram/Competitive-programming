#include <bits/stdc++.h>
using namespace std;
int main() {
	long t;
	cin>>t;
	while(t--) {
		long n, m;
		cin>>n>>m;
		vector<long> a(n, 0);
		set<pair<long, long> > sarr;
		vector<pair<long, long> > arr(m);
		for(long i=0;i<m;i++){
			cin>>arr[i].second>>arr[i].first;
			sarr.insert(arr[i]);
		}
		set<pair<long, long> >::iterator sit;
		arr.clear();
		for(sit = sarr.begin(); sit != sarr.end(); sit++){
			arr.push_back(*sit);
		}
		// sort(arr.begin(),arr.end());
		// for(long i=0;i<m;i++){
			// cout<<arr[i].first<<" "<<arr[i].second<<endl;
		// }
		long val = 1;
		bool flag = true;
		if(arr[0].first != 1) flag = false;
		if(flag)
			for(long i=0;i<m;i++) {
				long index = arr[i].first-1;
				long start = arr[i].second;
				// cout<<index<<" "<<start<<endl;
				if(start == 0){
					a[index] = val++;
				} else if(start > 0 && start-1 < index){
					// cout<<"index = "<<index<<"  copy from "<<start-1<<" value "<<a[start-1]<<endl;
					a[index] = a[start-1];
				} else {
					flag = false;
					break;
				}
				// if(index == 3)
					// cout<<a[index]<<" ******* "<<val-1<<" ****** "<<arr[start-1].second<<endl;
				i++; 
				start++;
				while(i < m && start <= index){
					if(arr[i].second != start || a[start-1] == a[index]){
						flag = false;
						break;
					}
					start++;
					i++;
				}
				// cout<<"index+1 = "<<index+1<<" arr[i].first = "<<arr[i].first<<endl;
				// cout<<"i = "<<i<<endl;
				if(i >=  m) break;
				if(arr[i].first-1 != index+1)
					flag = false;
				if(!flag) break;
				i--;
			}
		if(arr[arr.size()-1].first != n && arr[arr.size()-1].first != n-1) flag = false;
		if(flag){
			for(long i=0;i<n;i++) cout<<a[i]<<" ";
			cout<<endl;
		}
		else cout<<-1<<endl;
	}
	return 0;
}