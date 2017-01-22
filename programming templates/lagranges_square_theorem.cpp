// Express prime no congruent to 1 mod 4 as sum of two squares.
// Lagranges two squares theorem 
// Express any prime as a sum of 4 squares.
// Given two numbers as sum of 4 squares, express their product as sum of four squares Euler Identity
#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct squares_ans {
	ll a,b,c,d;
};
vector<pair<ll,ll> > prime_squares;
squares_ans prime(long long p) {
	squares_ans ans;
	if(p%4 == 1)
		ans.a = ans.b = 0;
	else
		ans.a = ans.b = 1;
	p -= ans.a+ans.b;
	ans.c = prime_squares[p].first;
	ans.d = prime_squares[p].second;
	return ans;
}
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
vector<ll> primes;
bool arr[1000001];
void markMultiples(int a, int n)
{
	primes.push_back(a);
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
            if ( arr[i] == false )
                markMultiples(i, n);
    }
}
squares_ans euler (squares_ans x, squares_ans y, ll mod) {
	squares_ans ans;
	ans.a = abs(x.a*y.a + x.b*y.b + x.c*y.c + x.d*y.d)%mod;
	ans.b = abs(x.a*y.b - x.b*y.a + x.c*y.d - x.d*y.c)%mod;
	ans.c = abs(x.a*y.c - x.c*y.a + x.d*y.b - x.b*y.d)%mod;
	ans.d = abs(x.a*y.d - x.d*y.a + x.b*y.c - x.c*y.b)%mod;
	return ans;
}
squares_ans find_four_squares(ll x, ll mod) {
	// if(arr[x]==false)
	// 	return prime(x);
	squares_ans ans;
	// ans.a = 1;
	// ans.b = ans.c = ans.d = 0;
	// long i = 0;
	// while(x!=1) {
	// 	if(primes[i]*primes[i] <= x) {
	// 		while(x%primes[i] == 0){
	// 			x /= primes[i];
	// 			ans = euler(prime(primes[i]),ans,mod);
	// 		}
	// 	} else {
	// 		ans = euler(prime(x),ans,mod);
	// 		break;
	// 	}
	// 	i++;
	// }
	for(set<ll>::iterator it = possible.begin();it!=possible.end();++it){
		if(possible.find(x-*it)!=possible.end()){
			ans.a = prime_squares[*it].first;
			ans.b = prime_squares[*it].second;
			ans.c = prime_squares[x-*it].first;
			ans.d = prime_squares[x-*it].second;
			break;
		}
	}
	return ans;
}
int main() {
	SieveOfEratosthenes(1000001);
	populate_prime_squares(1000001);
	// while(1) {
	// 	ll a;
	// 	cin>>a;
	// 	squares_ans ans = find_four_squares(a,100);
	// 	cout<<ans.a<<" "<<ans.b<<" "<<ans.c<<" "<<ans.d<<endl;
	// }

	squares_ans ans = find_four_squares(21,100000);
	cout<<ans.a<<" "<<ans.b<<" "<<ans.c<<" "<<ans.d<<endl;
	int c = 0;
	for(long i=1;i<=1000000;i++) {
		ll p = 1000000007;
		// cout<<i<<endl;
		squares_ans ans = find_four_squares(i,p);
		if((ans.a*ans.a + ans.b*ans.b + ans.c*ans.c + ans.d*ans.d)%p != i %p)
			if (arr[i]==false){
				cout<<i<<" "<<ans.a%p<<" "<<ans.b%p<<" "<<ans.c%p<<" "<<ans.d%p<<" "<<endl;
				c++;
			}
	}
	cout<<c<<endl;
	return 0;
}