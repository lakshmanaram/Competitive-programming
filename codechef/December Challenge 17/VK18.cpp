#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
using namespace std;
int main(){
	vector<long> arr(2000002);
	for(long i=0;i<arr.size();i++){
		int e,o;
		e = o = 0;
		long n = i;
		while(n){
			if((n%10)&1) o += n%10;
			else e += n%10;
			n/=10;
		}
		arr[i] = abs(e-o);
	}
	vector<long long> ans(1000001);
	ans[1] = 2;
	ll temp = 2;
	long start = 2;
	long end = 2;
	for(long i=2;i<ans.size();i++){
		temp -= 2*arr[start++];
		temp += arr[end++];
		temp += 2*arr[end++];
		temp += arr[end];
		ans[i] = ans[i-1]+temp;
	}
	int t;
	cin>>t;
	while(t--){
		long n;
		scanf("%d",&n);
		printf("%lld\n",ans[n]);
	}
	return 0;
}