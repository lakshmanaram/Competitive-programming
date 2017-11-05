#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
using namespace std;
long h,n;
map<pair<long, long>, ll> ma;
long long find_ans(long x, long m, long remaining) {
	long avail = h-x;
	long avail_col = m-x;
	if((avail*(avail+1))/2 >= remaining){
		if(ma.find(mp(avail_col,remaining))!=ma.end())
			return ma[mp(avail_col,remaining)];
	}
	if(remaining == 0) return 1;
	if(x >= h) return 0;
	long long ans = 0;
	// long long diff = ((h-x)*(h-x-1))/2;
	for(long i=remaining-1;i>=0;i--){
		long used = remaining-i;
		// long long check = (h-x)*used;
		// if(check-diff <remaining ) continue;
		if(x+used > m) break;
		if(x != 0)
			ans += (m-(x+used)+1)*find_ans(x+1,x+used,i);
		else
			ans += find_ans(x+1,x+used,i);
	}
	if((avail*(avail+1))/2 >= remaining){
		ma[mp(avail_col,remaining)] = ans;
	}
	return ans;
}
int main(){
	cin>>h>>n;
	cout<<find_ans(0,n,n)<<endl;
	return 0;
}