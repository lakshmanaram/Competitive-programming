#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
using namespace std;

vector<ll> primes;
vector<bool> barr;
void markMultiples(int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n ) {
        barr[num] = true;
        ++i;
    }
}
void SieveOfEratosthenes()
{
	long n = sqrt(1000000001);
    if (n >= 2) {
        barr.resize(n,false);
        for (int i=2; i<n; ++i)
            if ( barr[i] == false ){
            	primes.pb(i);
                markMultiples(i, n);
            }
    }
}
ll modInverse(ll a, ll b) {
	ll mod = b;
    ll x = 1, y = 0;
    ll xLast = 0, yLast = 1;
    ll q, r, m, n;
    while(a != 0) {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        b = a, a = r;
    }
    if(xLast < 0) {
    	if(-xLast >= mod)
    		return mod-((-xLast)%mod);
    	else return mod+xLast;
    }
    if(xLast >= mod) xLast %= mod;
    return xLast;
}
int main(){
	SieveOfEratosthenes();
	int t;
	scanf("%d",&t);
	while(t--) {
		ll n,p,q;
		scanf("%lld %lld %lld", &n, &p, &q);
		vector<ll> arr(n), marr(n);
		vector<ll> b(floor(q/64)+2);
		for(long i=0;i<n;i++){
			scanf("%lld",&arr[i]);
			if(arr[i] >= p) arr[i] %= p;
			if(arr[i] == 0) arr[i] = p;
		}
		for(long i=0;i<b.size();i++)
			scanf("%lld",&b[i]);

		vector<ll> facs;
		ll tem = p;
		vector<vector<ll> > cum_facs;
		vector<vector<ll> > memo;
		if(tem < primes.size() && !barr[tem]) {
			facs.pb(tem);
		} else {
			for(ll i=0;primes[i]*primes[i] <= tem;i++)
				if(tem%primes[i] == 0){
					while(tem % primes[i] == 0)	tem/=primes[i]; 
					facs.pb(primes[i]);
				}
			if(tem != 1) facs.pb(tem);
		}
		for(long i=0;i<facs.size();i++){
			vector<ll> temp, temp1(1,1);
			for(long j=0;j<n;j++){
				ll count = 0;
				while(arr[j]%facs[i] == 0){
					count++;
					arr[j] /= facs[i];
				}
				if(temp.size() == 0)
					temp.pb(count);
				else temp.pb(count + temp[j-1]);
			}
			cum_facs.pb(temp);
			if(facs[i] == p) {
				temp1.resize(temp[temp.size()-1]+1, 0);
			} else {
				for(long j=1;j<temp[temp.size()-1]+1;j++){
					temp1.pb((facs[i]*temp1[j-1])%p);
				}
			}
			memo.pb(temp1);
		}
		marr[0] = modInverse(arr[0],p);
		for(long i=1;i<n;i++){
			arr[i] = arr[i]*arr[i-1];
			if(arr[i] >= p) arr[i] %= p;
			marr[i] = modInverse(arr[i],p);
		}

		// for(long i=0;i<arr.size();i++) cout<<arr[i]<<" ";
		// cout<<endl;
		// for(long i=0;i<facs.size();i++){
		// 	cout<<facs[i]<<" ====> ";
		// 	for(long j=0;j<cum_facs[i].size();j++){
		// 		cout<<cum_facs[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		unsigned ll x = 0;
		ll prevl = 0;
		ll prevr = 0;
		unsigned ll y = ULLONG_MAX;
		y /= p;
		for(long k=0;k<q;k++){
			ll l,r;
			if(k%64 == 0) {
				l = b[k/64] + x;
				r = b[1+k/64] + x;
			} else {
				l = prevl+x;
				r = prevr+x;
			}
			if(l >= n) l %= n;
			if(r >= n) r %= n;
			if(r < l) swap(l,r);

			// cout<<"l = "<<l<<" r = "<<r<<endl;
			if(l != 0){
				x = arr[r]*marr[l-1];
				for(long i=0;i<cum_facs.size();i++){
					ll count = cum_facs[i][r] - cum_facs[i][l-1];
					if(count > 0) {
						if(x >= y) x %= p;
						x *= memo[i][count];
					}
				}
			} else {
				x = arr[r];
				for(long i=0;i<cum_facs.size();i++){
					ll count = cum_facs[i][r];
					if(count > 0) {
						if(x >= y) x %= p;
						x *= memo[i][count];
					}	
				}
			}
			x++;
			if(x >= p) x = x%p;
			prevl = l;
			prevr = r;
		}
		printf("%llu\n",x);
	}
	return 0;
}