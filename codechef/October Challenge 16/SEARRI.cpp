#include <bits/stdc++.h>
using namespace std;
int main() {
	long long n,k,d;
	cin>>n>>k>>d;
	vector<long long> arr(n);
	for(long long i=0;i<n;i++) {
		cin>>arr[i];
	}
	long long delval = 0;
	long delno = 0;
	vector<long> del;
	vector<bool> hash(n,false);
	while(d--) {
		long long avg = accumulate(arr.begin(),arr.end(),0) - delval;
		avg /= (n-delno);
		long long maxv = -1, maxp = -1, minv = -1, minp;
		for(long i=0; i<n ;i++){
			if(hash[i])
				continue;
			if(maxv == -1 || maxv < arr[i]){
				maxv = arr[i];
				maxp = i;
			}
			if(minv == -1 || minv > arr[i]) {
				minv = arr[i];
				minp = i;
			}
		}
		if ( maxv != -1 && (abs(avg-maxv) >= abs(avg - minv))){
			del.push_back(maxp);
			hash[maxp] = true;
			delval += arr[maxp];
			delno++;
			if(delno == n)
				break;
		} else if(minv != -1) {
			del.push_back(maxp);
			hash[minp] = true;
			delval += arr[minp];
			delno++;
			if(delno == n)
				break;
		}
	}
	long long swno = delno;
	vector<pair<int, int> > sw;
	while(k--) {
		if(delno == n)
			break;
		for(long j=0;j<n;j++) {
			if(hash[j])
				continue;
			long long avg = accumulate(arr.begin(),arr.end(),0) - delval;
			avg /= (n-delno);
			long long minv = -1, minp;
			for(long i=j+1; i<n ;i++){
				if(hash[i])
					continue;
				if(minv == -1 || minv > arr[i]) {
					minv = arr[i];
					minp = i;
				}
			}
			if(minv != -1) {
				sw.push_back(make_pair(j,minp));
				arr[minp] = arr[j];
				arr[j] = minv;
			}
			break;
		}
	}
	long long avg = accumulate(arr.begin(),arr.end(),0) - delval;
	if(delno == n){
		cout<<0<<" "<<0<<endl;
	} else {
	avg /= (n-delno);
	long long maxv = -1, maxp = -1, minv = -1, minp;
	for(long i=0; i<n ;i++){
		if(hash[i])
			continue;
		if(maxv == -1 || maxv < arr[i]){
			maxv = arr[i];
			maxp = i;
		}
		if(minv == -1 || minv > arr[i]) {
			minv = arr[i];
			minp = i;
		}
	}
		cout<<avg<<" "<<0<<endl;
	}
	for(long i=0;i<del.size();i++){
		cout<<2<<" "<<del[i]<<endl;
	}
	for(long i=0;i<sw.size();i++){
		cout<<1<<" "<<sw[i].first<<" "<<sw[i].second<<endl;
	}
	cout<<-1<<endl;
	return 0;
}