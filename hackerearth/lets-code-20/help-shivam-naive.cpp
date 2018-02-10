#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
int main(){
	long n;
	scanf("%ld", &n);
	vector<ll> arr(n);
	for(long i=0;i<n;i++){
		scanf("%lld", &arr[i]);
	}
	vll temp = arr;
	ll ans = 0;
	for(long i=arr.size()-2;i>=0;i--){
		if(arr[i] < arr[i+1] ){
			ans += abs(arr[i]-arr[i+1]);
			arr[i] = arr[i+1];
		}
	}
	arr = temp;
	ll tans = 0;
	for(long i=1;i<arr.size();i++) {
		if(arr[i] > arr[i-1]){
			tans += abs(arr[i]-arr[i-1]);
			arr[i] = arr[i-1];
		}
	}
	arr = temp;
	ans = min(ans, tans);
	sort(all(temp));
	vector<ll> ttt(n, 0);
	vector<vector<ll> > memo(n, ttt);
	for(long i=0;i<arr.size();i++){
		memo[n-1][i] = abs(temp[i] - arr[n-1]);
	}
	ll sum = arr[n-1];
	for(long i=arr.size()-2;i>=0;i--){
		ll min_so_far = -1;
		ll mval = -1;
		for(long j=0;j<arr.size();j++){
			ll mistakes = memo[i+1][j];
			ll no = temp[j];
			if(no <= arr[i]){
				if(mval == -1) mval = mistakes;
				else mval = min(mval, mistakes);
			}
			if(min_so_far == -1) min_so_far = mistakes;
			else min_so_far = min(min_so_far, mistakes);
		// if(min(mistakes, min_so_far) +abs(no-arr[i]) <= ans)
				memo[i][j] = min(mistakes, min_so_far) +abs(no-arr[i]);
		}
		// if(mval == -1)
		// 	mval = sum - (arr.size()-1-i)*arr[i];
		// if(mval <= ans)
		// 	ts.insert(mp(arr[i], mval));
		// 	s.clear();
			// cout<<"i = "<<i<<" -- ";
			// for(auto it = ts.begin(); it != ts.end(); it++){
			// 	cout<<it->first<<" no = "<<it->second<<"; ";
			// }
			// cout<<endl;
		sum += arr[i];
	}
	// for(long i=0;i<n;i++) cout<<arr[i]<<"     ";
	// 	cout<<endl;
	// for(long i=0; i< n; i++) {
	// 	for(long j=0;j<n;j++){
	// 		cout<<memo[i][j]<<"    ";
	// 	}
	// 	cout<<endl;
	// }
	printf("%lld\n",*min_element(all(memo[0])));
	return 0;
}
/*
8 7 4 3 9 1 2 6 4     
7 3 9 1 2 8 6 4
*/