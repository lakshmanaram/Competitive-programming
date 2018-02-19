#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
ll mod = 1000000007;
using namespace std;
long long pow(long long a, long long b) {
    long long x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod;
        b /= 2;
    }
    return x;
}
long long mmi(long long a) {
    return pow(a,mod-2);
}
int main(){
	ll n, m;
	S(n);
	S(m);
	vector<ll> a(n), b(n);
	for(long i = 0; i<n;i++){
		cin>>a[i];
	}
	for(long i = 0; i<n;i++){
		cin>>b[i];
	}
	ll num = 0, denom = 1;
	long i = 0;
	ll multip = 1;
	for(;i<n;i++) {
		if(a[i] == 0){
			if(b[i] == 0) {
				// ugly case
				num *= (m*m)%mod;
				num %= mod;
				num += multip*(((m*(m-1))/2)%mod);
				denom *= (m*m)%mod;
				num %= mod;
				denom %= mod;
				multip *= m;
				multip %= mod;
			} else {
				num *= m;
				num %= mod;
				num += multip*(m-b[i]);
				denom *= m;
				num %= mod;
				denom %= mod;
			}
		} else {
			if(b[i] == 0) {
				num *= m;
				num %= mod;
				num += multip*(a[i]-1);
				denom *= m;
				num %= mod;
				denom %= mod;
			} else {
				if(a[i] == b[i]) continue;
				if(a[i] > b[i]) num += multip;
				break;
			}
		}
	}
	// cout<<num << endl<< denom<<endl;
	num %= mod;
	denom %= mod;
	cout<<(num * mmi(denom))%mod<<endl;
	return 0;
}