#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

vector<long> primes;
bool arr[1000001];
void markMultiples(int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n ) {
        arr[num] = true;
        ++i;
    }
}
void SieveOfEratosthenes(int n)
{
    if (n >= 2) {
        fill(arr,arr+1000001,false);
        for (int i=2; i<n; ++i)
            if ( arr[i] == false ){
            	primes.pb(i);
                markMultiples(i, n);
            }
    }
}
bool isprime(int a)
{
    if(arr[a]==false)
        return true;
    return false;
}
void display_primes() {
	for(long i=0;i<primes.size();i++)
		cout<<primes[i]<<" ";
	cout<<endl;
}
vector<vector<long> > factors;

void get_prime_factorization(long j, ll l) {
	ll x = l+j;
	for(long i=0;i<factors[j].size();i++) {
		long count = 0;
		while(x%factors[j][i] == 0){
			count++;
			x /= factors[j][i];
		}
		factors[j][i] = count+1;
	}
	if(x != 1 && factors[j].size()!=0)
		factors[j].pb(2);
}
void display_factors() {
	for(long i=0;i<factors.size();i++) {
		for(long j=0;j < factors[i].size();j++)
			cout<<factors[i][j]<<" ";
		cout<<endl;
	}
}
ll get_ans(vector<long> a) {
	vector<long> b(a.size(),1);
	long long product = 1;
	ll ans = 0;
	sort(a.begin(),a.end());
	for(long i=0;i<a.size();i++) {
		while(a[i]!=b[i]) {
			for(long j = i; j<a.size();j++) {
				product /= b[j];
				b[j]++;
				product *= b[j];
				ans += product;
			}
		}
	}
	return ans;
}
ll segmentSieve(ll l, ll r) {
	SieveOfEratosthenes(ceil(sqrt(r))+2);
	factors.resize(r-l+1);
	for(long i=0;i<primes.size();i++) {
		long start = (primes[i] - (l%primes[i]))%primes[i];
		while(start <= r-l) {
			if(l+start != primes[i])
				factors[start].pb(primes[i]);
			start += primes[i];
		}
	}
	ll ans = 0;
	ll product = 1;
	for(long i=0; i< factors.size();i++) {
		get_prime_factorization(i,l);
		if(l == 1 && i == 0) {
			// ans += 1;
			continue;
		}
		if(factors[i].size()==0){
			ans+=2;
			continue;
		}
		// ll prev = ans;
		ans += get_ans(factors[i]);
		// if(ansmap.find(factors[i])!=ansmap.end())
		// 	ans += ansmap[factors[i]];
		// else {
		// 	ll tempans = 0;

		// 	ansmap[factors[i]] = tempans;
		// 	ans+=tempans;
		// }
		// cout<<l+i<<" "<<get_ans(factors[i])<<endl;
	}
	return ans;
}
int main()
{
    // SieveOfEratosthenes(1000001);
    ll x,y;
    cin>>x>>y;
    cout<<segmentSieve(x,y);
    return 0;
}
