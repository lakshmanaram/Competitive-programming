#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
ll get_mins(ll h, ll m){
	return h*60 + m;
}
pair<ll, ll> get_form(ll m){
	return mp(m/60, m%60);
}
bool ch(ll a){
	if(a%10 == 7)
		return true;
	return false;
}
int main(){
	ll x, h, m;
	S(x);
	S(h);
	S(m);
	ll val = get_mins(h, m);
	ll ans = 0;
	while(true){
		// cout<<"val = "<<val<<" ";
		pair<ll, ll> c = get_form(val);
		// cout<<c.first<<" "<<c.second<<" ";
		if(ch(c.first) || ch(c.second)){
			break;
		}
		val -= x;
		// cout<<val<<endl;
		if(val < 0) val += 24*60;
		ans++;
	}
	printf("%lld\n",ans);
	return 0;
}