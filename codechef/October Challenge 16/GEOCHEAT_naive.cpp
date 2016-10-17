#include <bits/stdc++.h>
using namespace std;
long long distance_pts ( pair<long long, long long> a, pair<long long, long long> b) {
	return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}
int main() {
	long long n;
	cin>>n;
	vector<pair<long long,long long > > points(n);
	long long d = 0;
	for(long long i=0;i<n;i++) {
		cin>>points[i].first>>points[i].second;
		for(long long j=0;j<i;j++){
			long long x = distance_pts(points[i], points[j]);
			if(x > d)
				d = x;
		}
		cout<<d<<endl;
	}
	return 0;
}