#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
ll n_limit, current, y;
int n_bits;
long n;
set<pair<ll, long> > sarr;
vector<bool> vis;
vector<ll> health;
int set_bits(ll &a){
	ll x = 1;
	int count = 0;
	while(x < n_limit){
		if(x & a) count++;
		x <<= 1;
	}
	return count;
}
void func(ll x, int bit, bool flag){
	// printf("inside func x = %lld, bit = %d, flag = %d\n", x, bit, flag?1:0);
	ll temp = 1LL << bit;
	while(temp < n_limit) {
		bit++;
		if((temp & x) && flag){
			func(((n_limit-1)^temp)&x, bit, flag); 
		} else if(!((temp & x) || flag)) {
			func(x|temp, bit, flag);
		}
		temp <<= 1;
	}
	if(bit == n_bits) {
		if(x >= n || vis[x]) return;
		sarr.erase(mp(health[x], x));
		if(flag) health[x] -= y;
		else health[x] += y;
		sarr.insert(mp(health[x], x));
		return;
	}
}
string get_bin(ll temp){
	string bin = "";
	while(temp){
		bin += (temp&1)?"1":"0";
		temp >>= 1;
	}
	reverse(all(bin));
	return bin;
}
ll get_val(string x){
	ll ans = 0;
	for(long i=0;i<x.size();i++){
		ans <<= 1;
		ans += (x[i] == '1')?1:0;
	}
	return ans;
}
ll find_ans(ll x, int sub){
	int s = set_bits(x);
	if(x < n){
		return pow(2, s-sub);
	}
	if(s == sub) {
		if(x < n) return 1;
		else return 0;
	}
	string bin = get_bin(x);
	int count = 0;
	for(int i=0;i<bin.size();i++) {
		if(bin[i] == '1') count++;
		if(count > sub){
			ll a = find_ans(x, sub+1);
			bin[i] = '0';
			a += find_ans(get_val(bin), sub);
			return a;
		}
	}
}
int main(){
	scanf("%ld", &n);
	n_bits = ceil(log2(n));
	n_limit = 1LL << n_bits;
	vis.resize(n, false);
	ll x;
	bool all_ones = true;
	for(long i=0;i<n;i++){
		scanf("%lld", &x);
		sarr.insert(mp(x, i));
		health.pb(x);
		if(x != 1) all_ones = false;
	}
	bool first = true;
	ll remaining = n;
	long t;
	scanf("%ld", &t);
	while(t--) {
		S(x);
		S(y);
		if(!all_ones){
			// cout<<x<<" sbits = "<<set_bits<<endl;
			// if(set_bits(x) <= n_bits/2) {
				// cout<<"choosing to manipulate 1\n";
				func(x, 0, true);
			// } else {
			// 	cout<<"choosing to manipulate 0\n";
			// 	func(x, 0, false);
			// 	current += y;
			// }
			for(auto it = sarr.begin(); it != sarr.end();) {
				auto temp = it;
				it++;
				if(temp->first <= current) {
					vis[temp->second] = true;
					sarr.erase(temp);
				} else break;
			}
			// cout<<"\nleftovers current = "<<current<<"\n";
			// for(auto it = sarr.begin(); it != sarr.end(); it++) {
			// 	cout<<it->second<<" "<<it->first<<"\n";
			// }
			// cout<<endl;
			printf("%lu\n", sarr.size());
		} else {
			if(first){
				current = x;
				remaining -= find_ans(x, 0);
				first = false;
			} else {
				cout<< find_ans(x, 0)<<" "<<x<<endl;
				cout<< find_ans(current&x, 0)<<" "<<(current&x)<<endl;
				remaining -= find_ans(x, 0) - find_ans(current&x, 0);
				current |= x;
			}
			printf("%lld\n", remaining);
		}
	}
	return 0;
}