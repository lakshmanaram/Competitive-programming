#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
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

int main(){
	ll n, m;
	S(n);
	S(m);
	SieveOfEratosthenes(1000001);
	ll s = n-3;
	ll val = -1;
	ll count = -1;
	while(val == -1){
		s++;
		count++;
		for(long i=0;i<primes.size() && (s + primes[i] < 1000001);i++){
			if(isprime(primes[i] + s)){
				val = primes[i];
				break;
			}
		}
	}
	// cout<<s<<" "<<val<<" "<<count<<endl;
	printf("%lld %lld\n", val, s+val);
	m -= n-1;
	long i;
	for(i = 2; i < n - count; i++){
		printf("1 %ld 1\n", i);
	}
	for(; i < n; i++){
		printf("1 %ld 2\n", i);
	}
	printf("1 %lld %lld\n", n, val);
	i = 2;
	while(m){
		for(long j = i+1; (j <= n) && m; j++,--m){
			printf("%ld %ld %lld", i, j, max(val+1, 3LL));
		}
		i++;
	}
	return 0;
}