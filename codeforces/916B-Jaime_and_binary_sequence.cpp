#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
using namespace std;
int main(){
	ll n, k;
	cin>>n>>k;
	vector<ll> arr(200001, 0);
	ll m = n;
	vector<ll> temp;
	while(m) {
		temp.pb(m%2);
		k -= m%2;
		m>>=1;
	}
	// reverse(all(temp));
	for(long i=0;i<temp.size();i++){
		arr[199900 + i] = temp[i];
	}
	// for(long i=0;i<temp.size();i++){
	// 	cout<<arr[199900 + i]<<" ";
	// }
	// cout<<endl;
	if(k < 0) printf("No\n");
	else {
		printf("Yes\n");
		ll i = arr.size()-1;
		while(k > 0){
			if(k >= arr[i]){
				ll val = arr[i];
				arr[i] -= val;
				arr[i-1] += val;
				arr[i-1] += val;
				k -= val;
				i--;
			} else {
				break;
			}
		}
		i = 0;
		while( i < arr.size()){
			if(arr[i] > 0) break;
			i++;
		}
		while(k > 0){
			arr[i]--;
			arr[i-1] += 2;
			i--;
			k--;
		}
		for(i = arr.size()-1; i >= 0; i--){
			for(long j=0;j<arr[i];j++){
				cout<<i-199900<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}