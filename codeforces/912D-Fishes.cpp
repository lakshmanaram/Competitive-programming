#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(),S.end()
#define S(a) scanf("%lld", &n)
using namespace std;
ll n, m, r, k;
ll find_ans(ll a, ll b){
	ll x = max(0LL, n-(a-1)*2);
	ll y = max(0LL, m-(b-1)*2);
	return x*y;
}
int main(){
	cin>>n>>m>>r>>k;
	ll denom = 0, num = 0;
	denom = (n-r+1)*(m-r+1);
	if( n < m ) swap(n, m);
	ll a0 = min(n-r+1, r);
	ll b0 = min(m-r+1, r);
	set<pair<long long, long> > s;
	set<pair<long long, long> >::iterator sit;
	s.insert(mp(a0*b0, a0));
	while(k){
		sit = s.end();
		sit--;
		ll a = sit-> second;
		ll b = (sit->first)/a;
		s.erase(sit);
		s.insert(mp((a-1)*b, a-1));
		s.insert(mp(a*(b-1), a));
		ll sq = find_ans(a, b);
		if(a+1 <= a0) 
			sq -= find_ans(a+1, b);
		if(b+1 <= b0) 
			sq -= find_ans(a, b+1);
		if(a+1 <= a0 && b+1 <= b0)
			sq += find_ans(a+1, b+1);
		if(sq < k){
			k -= sq;
			num += sq*a*b;
		} else {
			num += k*a*b;
			break;
		}
	}
	double ans = num;
	ans /= denom;
	printf("%.10lf\n", ans);
	return 0;
}