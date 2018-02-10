#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
using namespace __gnu_pbds;

typedef tree<
pair<long, long>,
null_type,
less<pair<long, long> >,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main(){
	long n;
	scanf("%ld", &n);
	vector<ll> arr(n);
	for(long i=0;i<n;i++){
		scanf("%lld", &arr[i]);
	}
	ordered_set s;
	vector<ll> ans(n, 0);
	s.insert(mp(arr[n-1], n-1));
	for(long i=n-2;i>=0;i--){
		ans[i] = s.order_of_key(mp(arr[i], -1));
		s.insert(mp(arr[i], i));
	}
	for(auto it = ans.begin(); it != ans.end(); it++){
		printf("%lld ", *it);
	}

	// s.insert(mp(12, 2));
	// s.insert(mp(4, 1));
	// cout<<s.order_of_key(mp(12, -1));
	// assert(*s.find_by_order(0) == 12);
	// assert(s.order_of_key(12) == 0);
	return 0;
}