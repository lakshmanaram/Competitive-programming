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
void segmentSieve(ll l, ll r) {
	SieveOfEratosthenes(ceil(sqrt(r))+2);
	factors.resize(r-l+1);
	for(long i=0;i<primes.size();i++) {
		long start = (primes[i] - (l%primes[i]))%primes[i];
		while(start <= r-l) {
			factors[start].pb(primes[i]);
			start += primes[i];
		}
	}
}
void display_factors() {
	for(long i=0;i<factors.size();i++) {
		for(long j=0;j < factors[i].size();j++)
			cout<<factors[i][j]<<" ";
		cout<<endl;
	}
}
void get_prime_factorization(long j, ll l) {
	for(long i=0;i<factors[j].size();i++) {
		long count = 0;
		while((l+j)%factors[j][i] == 0)
			count++;
		factors[j][i] = count;
	}
}

int main()
{
    // SieveOfEratosthenes(1000001);
    ll x,y;
    cin>>x>>y;
    segmentSieve(x,y);
    display_factors();
    return 0;
}

