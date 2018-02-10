#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
long check (string a, string b) { 
	vector<int> ar(26, 0), br(26, 0);
	for(long i=0;i<a.size();i++){
		ar[a[i]-'a']++;
		br[b[i]-'a']++;
	}
	ll ans = 0;
	for(long i=0;i<ar.size();i++) {
		ans += max(ar[i], br[i]) - min(ar[i], br[i]);
	}
	return ans;
}
int main(){
	long t;
	scanf("%ld", &t);
	while(t--) {
		long n;
		scanf("%ld", &n);
		string x, a[4];
		cin>>x;
		for(long i=0;i<4;i++) a[i] = "";
		long fac = x.size()/4;
		for(long i=0;i<x.size();i++){
			a[i/fac] += x[i];
		}
		ll ans = check(a[0], a[3]) + check (a[1], a[2]);
		if(ans == 0){
			cout<<"YES\n";
		} else {
			cout<<"NO "<<ans<<endl;
		}
	}
	return 0;
}