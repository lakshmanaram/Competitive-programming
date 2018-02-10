#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
ll find_mid(vll & arr, ll a, ll b){
	ll mid = (a+b)/2;
	ll val = a;
	ll left = 0, right = 0;
	for(long i=0;i<arr.size();i++){
		if(arr[i] <= mid){
			val = max(val, arr[i]);
			left++;
		} else right++;
	}
	if(left == right+(arr.size()&1)) return val;
	else if(left < right+(arr.size()&1)) return find_mid(arr, mid+1, b);
	else return find_mid(arr, a, mid);
}
ll find_median(vll &arr){
	if(arr.size() == 1) return arr[0];
	return find_mid(arr, *min_element(all(arr)), *max_element(all(arr)));
}
int main(){
	long n;
	scanf("%ld", &n);
	vector<ll> arr(n);
	set<pair<ll, long> > s;
	for(long i=0;i<n;i++){
		scanf("%lld", &arr[i]);
		s.insert(mp(arr[i], i));
	}
	vll temp = arr;
	set<long> ans_s;
	long pos = n-1;
	while(!s.empty()){
		ll val = s.begin()->first;
		ll ind = s.begin()->second;
		s.erase(s.begin());
		if(ind > pos) continue;
		// cout<<val<<" "<<ind<<" being processed\n";
		vll temparr;
		ll tpos = pos;
		while(pos != ind)
			temparr.pb(arr[pos--]);
		temparr.pb(arr[pos]);
		ll med = find_median(temparr);
		bool flag = true;
		while(!s.empty()) {
			if(s.begin()->second > pos){
				s.erase(s.begin());
			} else {
				if(s.begin()->first < med){
					flag = false;
				}
				break;
			}
		}
		if(flag){
			ans_s.insert(ind);
			arr[pos--] = med;
		} else {
			pos = tpos;
		}
	}
	pos = 1;
	ans_s.insert(n);
	for(auto it = ans_s.begin(); it != ans_s.end(); it++){
		cout<<*it<<" ";
		if(*it == 0) continue;
		while(pos < *it){	
			arr[pos] = arr[pos-1];
			pos++;
		}
		pos++;
	}
	cout<<endl;
	for(long i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	ll ans = 0;
	for(long i=0;i<arr.size();i++) ans += abs(temp[i] - arr[i]);
	printf("%lld\n",ans);
	return 0;
}
/*
8 7 4 3 9 1 2 6 4  
8 3 0 -1 5 -3 -2 2 0   
*/