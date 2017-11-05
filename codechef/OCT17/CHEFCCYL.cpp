#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
using namespace std;
class cycle {
public:
	bool trivial;
	vector<long> arr;
	vector<long long> cum_arr;
	void inp(long n){
		if(n == 1) {
			arr.resize(n);
			for(long i = 0; i < n; ++i)
				scanf("%ld",&arr[i]);
			trivial = true;
			return;
		}
		else trivial = false;
		arr.resize(n);
		for(long i = 0; i < n; ++i)
			scanf("%ld",&arr[i]);
		// cout<<"taken something\n";
		process();
	}
	void process(){
		long long sum = 0;
		for(long i = 0; i < arr.size(); ++i){
			sum += arr[i];
			cum_arr.pb(sum);
		}
	}
	long long answer(long i, long j){
		if(trivial) return 0;
		if(i==j) return 0;
		i--;
		j--;
		if(i > j) swap(i,j);
		ll ans;
		if(i != 0) {
			ans = cum_arr[j-1] - cum_arr[i-1];
			ans = min(ans, cum_arr[arr.size()-1]-cum_arr[j-1] + cum_arr[i-1]);
		}
		else {
			ans = cum_arr[j-1];
			ans = min(ans, cum_arr[arr.size()-1]-cum_arr[j-1]);
		}
		return ans;
	}
	long long manswer(long i, long j, long p, long q){
		i--;
		j--;
		ll ans;
		if(i != 0) {
			ans = p + cum_arr[j-1] - cum_arr[i-1];
			ans = min(ans, q + cum_arr[arr.size()-1]-cum_arr[j-1] + cum_arr[i-1]);
		}
		else {
			ans = p + cum_arr[j-1];
			ans = min(ans, q + cum_arr[arr.size()-1]-cum_arr[j-1]);
		}
		return ans;
	}
};
int main(){
	int t;
	cin>>t;
	while(t--){
		long n, m;
		cin>>n>>m;
		vector<cycle> c(n);
		for(long i=0;i<n;i++){
			long x;
			cin>>x;
			c[i].inp(x);
			// cout<<c[i].arr.size()<<endl;
		}
		vector<long> rhs, lhs;
		cycle o;
		for(long i=0;i<n;i++){
			long x, y, z;
			scanf("%ld %ld %ld", &x, &y, &z);
			// cin>>x>>y>>z;
			rhs.pb(x);
			if(i == n-1) lhs.insert(lhs.begin(),y);
			else lhs.pb(y);
			o.arr.pb(z);
		}
		o.process();
		// cout<<o.arr.size()<<endl;
		while(m--){
			long v1, c1, v2, c2;
			// cin>>v1>>c1>>v2>>c2;
			scanf("%ld %ld %ld %ld", &v1, &c1, &v2, &c2);
			if(c1 > c2){
				swap(c1, c2);
				swap(v1, v2);
			}
			ll clockwise = c[c1-1].answer(v1, rhs[c1-1]) + c[c2-1].answer(v2, lhs[c2-1]);
			ll anticlockwise = c[c1-1].answer(v1, lhs[c1-1]) + c[c2-1].answer(v2, rhs[c2-1]);
			ll ans = o.manswer(c1, c2, clockwise, anticlockwise);
			printf("%lld\n", ans);
		}
	}
	return 0;
}