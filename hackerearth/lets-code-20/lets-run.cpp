#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
ll mod = 1E9+7;
long long pow(long long a, long long b) {
    long long x = 1, y = a;
    while(b > 0) {
        if(b&1) {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod;
        b >>= 1;
    }
    return x;
}
long long mmi(long long a) {
    return pow(a,mod-2);
}
int main(){
	long t;
	scanf("%ld", &t);
	while(t--) {
		ll v, dt, n, q;
		S(v);
		S(dt);
		S(n);
		S(q);
		ll nt = t/dt;
		t -= nt*dt;
		ll deno = mmi(n+1);
		ll num = v*dt;
		num %= mod;
		ll npow = pow(n, nt);
		bool pos = false;
		if(nt&1) pos = true;
		if(!pos) npow = mod - (npow%mod);
		npow++;
		npow %= mod;
		num *= npow;
		num %= mod;
		ll ans = num*deno;
		ans %= mod;
		if(pos) ans -= ((v*t)%mod)*pow(n, nt);
		else ans += ((v*t)%mod)*pow(n, nt);
		if(ans < 0){
			ans = -ans;
			ans = mod - (ans%mod);
		}
		ans %= mod;
		printf("%lld\n", ans);
	}
	return 0;
}