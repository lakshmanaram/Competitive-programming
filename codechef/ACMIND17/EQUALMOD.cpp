#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
using namespace std;
class ob{
public:
	ll a;
	ll b;
	ll c;
	ll d;
	ob (ll a1, ll b1, ll c1, ll d1){
		a = a1;
		b = b1;
		c = c1;
		d = d1;
	}
};
bool comp(ob a, ob b){
	if(a.c <= b.c) return true;
	if(a.c > b.c) return false;
}
int main(){
	long t;
	scanf("%ld",&t);
	while(t--) {
		long n;
		scanf("%ld",&n);
		vector<ll> a(n),b(n);
		vector<ob> probs;
		for(long i=0;i<a.size();i++){
			scanf("%lld",&a[i]);
		}
		ll x;
		for(long i=0;i<a.size();i++){
			scanf("%lld",&b[i]);
			if(i == 0) x = b[i];
			else x = min(x,b[i]);
		}
		ll extra = 0;
		ll ans = 0;
		for(long i=0;i<n;i++){
			if(a[i]%b[i] < x){
				ob temp(a[i],b[i],a[i]%b[i], b[i]-(a[i]%b[i]));
				probs.push_back(temp);
			} else {
				extra++;
				ans += b[i] - (a[i]%b[i]);
			}
		}
		sort(probs.begin(),probs.end(), comp);
		vector<ll> cum_mod(probs.size()+1);
		cum_mod[0] = 0;
		for(long i=0;i<probs.size();i++){
			cum_mod[i+1] += cum_mod[i] + probs[i].c;
		}
		vector<ll> cum_tobe(probs.size()+1);
		cum_tobe[probs.size()] = 0;
		for(long i=probs.size()-1;i>=0;i--){
			cum_tobe[i] += cum_tobe[i+1] + probs[i].d;
		}
		ll temp_ans = cum_tobe[0];
		for(long i=0;i<probs.size();){
			long j = i+1;
			for(;j<probs.size();j++)
				if(probs[j].c != probs[i].c) break;
			ll cur_ans = probs[i].c*extra;
			cur_ans += i*probs[i].c - cum_mod[i];
			cur_ans += (probs.size()-j)*probs[i].c + cum_tobe[j];
			if(cur_ans < temp_ans){
				temp_ans = cur_ans;
			}
			i = j;
		}
		cout<<ans+temp_ans<<endl;
		// cout<<"==========================================\n";
		// for(long i=0;i<probs.size();i++) cout<<probs[i].a<<" ";
		// cout<<endl;
		// for(long i=0;i<probs.size();i++) cout<<probs[i].b<<" ";
		// cout<<endl;
		// for(long i=0;i<probs.size();i++) cout<<probs[i].c<<" ";
		// cout<<endl;
		// for(long i=0;i<probs.size();i++) cout<<probs[i].d<<" ";
		// cout<<endl;
		// for(long i=0;i<probs.size();i++) cout<<cum_mod[i]<<" ";
		// cout<<cum_mod[probs.size()]<<" "<<endl;
		// for(long i=0;i<probs.size();i++) cout<<cum_tobe[i]<<" ";
		// cout<<cum_tobe[probs.size()]<<" "<<endl;
		// cout<<"==========================================\n";
	}
	return 0;
}