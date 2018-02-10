#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
vector<ll> arr;
ll find_mid(ll a, ll b){
	// cout<<a<<" "<<b<<endl;
	ll mid = (a+b)/2;
	ll val = a;
	ll left = 0, right = 0;
	for(long i=0;i<arr.size();i++){
		if(arr[i] <= mid){
			val = max(val, arr[i]);
			left++;
		} else right++;
	}
	// cout<<left<<" "<<right<<endl;
	if(left == right+(arr.size()&1)) return val;
	else if(left < right+(arr.size()&1)) return find_mid(mid+1, b);
	else return find_mid(a, mid);
}
int main(){
	long n;
	scanf("%ld", &n);
	arr.resize(n);
	for(long i=0;i<n;i++){
		scanf("%lld", &arr[i]);
	}
	cout<<find_mid(*min_element(all(arr)), *max_element(all(arr)));
	return 0;
}
/*
8 10000000000 1 2 3 100 1212 131 121121212
*/