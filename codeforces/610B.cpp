//Codeforces Round #337 (Div. 2) B
#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin>>n;
	vector<long long> a;
	for(long long i=0;i<n;i++){
		long long x;
		cin>>x;
		a.push_back(x);
	}
	long long minval = a[0];
	long long minin = 0;
	long long maxin = 0;
	long long dist = 0;
	for(long long i=1;i<n;i++){
		if(a[i]<minval){
			minval = a[i];
			minin = i;
			maxin = i;
			dist = 0;
		}
		else if(a[i]==minval){
			dist = max(dist,i - maxin -1);
			maxin = i;
		}
	}
	dist = max(dist,n-(maxin-minin+1));
	cout<<minval*n+dist;
	return 0;
}