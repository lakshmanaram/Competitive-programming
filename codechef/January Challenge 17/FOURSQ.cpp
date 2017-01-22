#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct squares_ans {
	ll a,b,c,d;
};
vector<squares_ans> nos;
vector<pair<ll,ll> > prime_squares;
set<ll> possible;
void populate_prime_squares(long n) {
	prime_squares.resize(n+2);
	for(ll i=0; i*i <= n; i++) {
		for(ll j=0; j*j+i*i <= n; j++) {
			prime_squares[i*i+j*j] = make_pair(i,j);
			possible.insert(i*i+j*j);
		}
	}
}
ll c;
ll mm (ll a, ll b) {
	return (a*(b%1048576)+((a<<20)%c)*(b>>20))%c;
}
squares_ans euler (squares_ans x, squares_ans y) {
	squares_ans ans;
	ans.a = abs(mm(x.a, y.a) + mm(x.b, y.b) + mm(x.c, y.c) + mm(x.d, y.d))%c;
	ans.b = abs(mm(x.a, y.b) - mm(x.b, y.a) + mm(x.c, y.d) - mm(x.d, y.c))%c;
	ans.c = abs(mm(x.a, y.c) - mm(x.c, y.a) + mm(x.d, y.b) - mm(x.b, y.d))%c;
	ans.d = abs(mm(x.a, y.d) - mm(x.d, y.a) + mm(x.b, y.c) - mm(x.c, y.b))%c;
	return ans;
}
squares_ans find_four_squares(ll x) {
	squares_ans ans;
	for(set<ll>::iterator it = possible.begin();it!=possible.end();++it){
		if(possible.find(x-*it)!=possible.end()){
			ans.a = prime_squares[*it].first;
			ans.b = prime_squares[*it].second;
			ans.c = prime_squares[x-*it].first;
			ans.d = prime_squares[x-*it].second;
			return ans;
		}
	}
}
squares_ans find_four_squares_mod(ll x, ll mod) {
	squares_ans ans = nos[x];
	ans.a %= mod;
	ans.b %= mod;
	ans.c %= mod;
	ans.d %= mod;
	return ans;
}
class segment_tree{
public:
	vector<squares_ans> tnodes;
	vector<squares_ans> arr;
	ll mod;
	squares_ans one;
	segment_tree(long n, ll p){
		mod = p;
		arr.resize(n);
		for(long i=0;i<n;i++){
			ll x;
			scanf("%lld",&x);
			arr[i] = find_four_squares_mod(x,mod);
		}
		one.d = one.b = one.c = 0;
		one.a = 1;
	}
	void build_segment_tree(long index, long start, long end) {
		if(start == end){
			if(tnodes.size() <= index)
				tnodes.resize(index+1);
			tnodes[index] = arr[start];
		} else {
			long mid = (start+end)/2;
			build_segment_tree(2*index+1,start,mid);
			build_segment_tree(2*index+2,mid+1,end);
			tnodes[index] = euler(tnodes[2*index+1], tnodes[2*index+2]);
		}
	}
	squares_ans query_range(long index, long start, long end, long l, long r) {
		if(start > r || end < l)
			return one;
		if(start >= l && end <= r)
			return tnodes[index];
		long mid = (start+end)/2;
		squares_ans val1 = query_range(2*index+1, start, mid, l, r);
		squares_ans val2 = query_range(2*index+2, mid+1, end, l, r);
		return euler(val1, val2);
	}
	void update(long index, long start, long end, long pos, ll val) {
		if(start == end){
			arr[pos] = tnodes[index] = find_four_squares_mod(val,mod);
		} else {
			long mid = (start+end)/2;
			if(start <= pos && mid >= pos)
				update(2*index+1,start,mid,pos,val);
			else
				update(2*index+2,mid+1,end,pos,val);
			tnodes[index] = euler(tnodes[2*index+1], tnodes[2*index+2]);
		}
	}
	void update_query() {
		long pos;
		ll val;
		scanf("%ld %lld",&pos,&val);
		update(0,0,arr.size()-1,pos-1,val);
	}
};
int main() {
	populate_prime_squares(1000001);
	for(long i=0;i<1000001;i++){
		nos.push_back(find_four_squares(i));
	}
	int t;
	scanf("%d",&t);
	while(t--) {
		long n, q;
		ll p;
		scanf("%ld %ld %lld",&n,&q,&p);
		c = p;
		segment_tree st(n,p);	
		st.build_segment_tree(0,0,st.arr.size()-1);
		while(q--) {
			int ch;
			scanf("%d",&ch);
			if(ch == 1) {
				st.update_query();
			} else {
				long l,r;
				scanf("%ld %ld",&l,&r);
				squares_ans ans = st.query_range(0,0,st.arr.size()-1,l-1,r-1);
				printf("%lld %lld %lld %lld\n",ans.a,ans.b,ans.c,ans.d);
			}
		}
	}

	return 0;
}