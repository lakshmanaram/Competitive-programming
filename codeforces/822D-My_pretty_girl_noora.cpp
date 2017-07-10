#include <bits/stdc++.h>
#define pb push_back
using namespace std;
long long mod = 1000000007;
long long arr[5000001];
void markMultiples(long long a, long long n)
{
    long long i = a, num;
    arr[a] = a;
    while ( (num = i*a) < n ) {
        if(arr[num] == -1)
        	arr[num] = a;
        i += 2;
    }
}
void SieveOfEratosthenes(long long n)
{
    if (n >= 2) {
        fill(arr,arr+n,-1);
        for(long long i=2;i<n;i+=2)
        	arr[i] = 2;
        for (long long i=3; i<n; i+=2)
            if ( arr[i] == -1 ){
                markMultiples(i, n);
            }
    }
}
long long get_val(long long x){
	if(x == 1)
		return 0;
	long long ans = arr[x];
	ans--;
	ans *= x;
	ans /= 2;
	ans %= mod;
	return (ans+get_val(x/arr[x]))%mod;
}
int main(){
	SieveOfEratosthenes(5000001);
	long long t, l, r;
	cin>>t>>l>>r;
	t %= mod;
	long long ans = 0;
	long long val = 1;
	for(long long i=l;i<=r;i++){
		ans += val*get_val(i);
		ans %= mod;
		val *= t;
		val %= mod;
	}
	cout<<ans;
	return 0;
}