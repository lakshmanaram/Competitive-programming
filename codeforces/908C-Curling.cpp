#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
using namespace std;
int main(){
	long n, m;
	cin>>n>>m;
	vll arr(n);
	for(long i=0;i<n;i++) cin>>arr[i];
	vector<double> centers(1010, -m);
	for(long i=0;i<arr.size();i++){
		double val = 0;
		for(long j=1;j<=1000;j++){
			double x = j - arr[i];
			x *= x;
			double r = 4*m*m;
			if(x > r) continue;
			// cout<<x<<" "<<r<<endl;
			r -= x;
			r = sqrt(r);
			val = max(val, r+centers[j]);
		}
		printf("%.8lf ", val);
		centers[arr[i]] = val;
	}
	return 0;
}